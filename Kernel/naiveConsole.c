#include <naiveConsole.h>
#include <font.h>
#include <stdlib.h>

struct vbe_mode_info_structure * screenInfo;  //en sysvar encontramos estos datos cargados
static uint8_t * currentVideo;
static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base);
static uint16_t width;
static uint16_t height;
static uint8_t bpp;



static char buffer[64] = { '0' };
// uint8_t * const video = screenInfo->framebuffer;
// const uint32_t width = screenInfo->width;
// const uint32_t height = screenInfo->height;

typedef struct pos{
	int x;
	int y;
}pos;

pos currentPos;

void startPos(){
	screenInfo = (void *) 0x5C00; 
	currentPos.x = 0;
	currentPos.y = 0;
	currentVideo = screenInfo->framebuffer;
	width = screenInfo->width;
	height = screenInfo->height;
	bpp = screenInfo->bpp;
}

static void putpixel(unsigned char* screen, int x,int y, int color) {
    unsigned where = x*screenInfo->bpp/8 + y*screenInfo->pitch;
    screen[where] = color & 255;              // BLUE
    screen[where + 1] = (color >> 8) & 255;   // GREEN
    screen[where + 2] = (color >> 16) & 255;  // RED
}
 
void drawcharAt(unsigned char c, int x, int y, int fgcolor, int bgcolor) {
	int cx,cy;
	int mask[8]={1,2,4,8,16,32,64,128};
	unsigned char *glyph=fb_font+(int)c*FONT_SCANLINES;
	for(cx=0;cx<8;cx++){
		for(cy=0;cy<16;cy++){
			putpixel((unsigned char*)currentVideo,x+cx, y+cy, glyph[cy]&mask[7-cx]?fgcolor:bgcolor);
		}
	}
}

void drawChar(unsigned char c,int fgcolor, int bgcolor){
	drawcharAt(c,currentPos.x,currentPos.y,fgcolor,bgcolor);
	if(currentPos.x < width){
		currentPos.x+= 10;
	}
	else if(currentPos.y < height){
		currentPos.x = 0;
		currentPos.y+=16;
	}
	//generar funcion que mueva toto un renglon hacia arriba porque llegamos al final de la terminal.
}

unsigned int getBpp(){
	return (screenInfo->bpp)/8;
}

void fillRect(unsigned char * vram, unsigned char r, unsigned char g, unsigned char b, unsigned char w, unsigned char h){
	unsigned char * where = screenInfo->framebuffer + vram;
	int i, j;
	int pixelWidth = getBpp();
	for(i = 0; i < w; i++){
		for(j = 0; j < h;j++){
			where[j*pixelWidth] = r;
			where[j*pixelWidth + 1] = g;
			where[j*pixelWidth + 2] = b;
		}
		where += screenInfo->pitch;
	}
	
}

void ncPrint(const char * string)
 {
 	int i;

 	for (i = 0; string[i] != 0; i++)
		ncPrintChar(string[i]);
 }

 void ncPrintChar(char character)
{
	*currentVideo = character;
	currentVideo += 2;
}

void ncPrintDec(uint64_t value)
{
	ncPrintBase(value, 10);
}

void ncPrintHex(uint64_t value)
{
	ncPrintBase(value, 16);
}

void ncPrintBin(uint64_t value)
{
	ncPrintBase(value, 2);
}

void ncNewline()
{
	for(int i = currentPos.x; i<width;i++){
			putpixel((unsigned char*)currentVideo,i,currentPos.y,0x000000);
	}
}


void ncPrintBase(uint64_t value, uint32_t base)
{
    uintToBase(value, buffer, base);
    ncPrint(buffer);
}

void ncClear()
{
 	int i,j;

 	for(i = 0; i < width;i++){
		for(j = 0; j < height;j++){
			putpixel((unsigned char*)currentVideo,i,j,0x000000);
		}
	} //ahora cuando termine esta llamada vemos que hacemos
}

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base)
{
	char *p = buffer;
	char *p1, *p2;
	uint32_t digits = 0;

	//Calculate characters for each digit
	do
	{
		uint32_t remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
		digits++;
	}
	while (value /= base);

	// Terminate string in buffer.
	*p = 0;

	//Reverse string in buffer.
	p1 = buffer;
	p2 = p - 1;
	while (p1 < p2)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}

	return digits;
}