#include <naiveConsole.h>
#include <font.h>
#include <stdlib.h>

struct vbe_mode_info_structure * screenInfo;  //en sysvar encontramos estos datos cargados
static uint8_t * currentVideo;
static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base);
static uint16_t width;
static uint16_t height;
static uint8_t bpp;
static uint16_t size;



static char buffer[64] = { '0' };
// uint8_t * const video = screenInfo->framebuffer;
// const uint32_t width = screenInfo->width;
// const uint32_t height = screenInfo->height;

pos currentPos;

void startPos(){
	screenInfo = (void *) 0x5C00; 
	currentPos.x = 0;
	currentPos.y = 0;
	currentVideo = screenInfo->framebuffer;
	width = screenInfo->width;
	height = screenInfo->height;
	bpp = screenInfo->bpp;
	size = 1;
}

uint32_t getHeight(){
	return height;
}
uint32_t getWidth(){
	return width;
}
uint32_t getScreen(){
	return screenInfo->framebuffer;
}
int compare(pos p1, pos p2){
	if(p1.x == p2.x && p1.y == p2.y)
		return 1;
	return 0;
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
			putpixel((unsigned char*)currentVideo,x+cx*size, y+cy*size, glyph[cy]&mask[7-cx]?fgcolor:bgcolor);
		}
	}
}

void drawChar(unsigned char c,int fgcolor, int bgcolor){
	if(currentPos.x + 8*size > width-8*size){
		ncNewline();
	}
	drawcharAt(c,currentPos.x,currentPos.y,fgcolor,bgcolor);
	if(currentPos.x < width-8*size){
		currentPos.x+= 8*size;
	}
	else if(currentPos.y < height-16*size){
		currentPos.x = 0;
		currentPos.y+=16*size;
	}
	else
		moveUp();
}

void moveUp(){
	unsigned where, current;
	for (int i = 0; i < height; i++)
	{
		for(int j = 0; j<width;j++){
			if(i < height - 16*size){
				current = j*screenInfo->bpp/8 + i*screenInfo->pitch;
				where = j*screenInfo->bpp/8 + (i+16)*screenInfo->pitch;
				currentVideo[current] = currentVideo[where];
				currentVideo[current+1] = currentVideo[where+1] >> 8;
				currentVideo[current+2] = currentVideo[where+2] >> 16;
			}
			else{
				drawChar(' ',BLANCO,NEGRO);
			}
		}
	}
	currentPos.y = height - 16*size;
	currentPos.x = 0;
}

unsigned int getBpp(){
	return (screenInfo->bpp)/8;
}

void nResize(int num){
	size = num;
}

void deleteChar(){
	drawcharAt(' ',currentPos.x-8*size,currentPos.y,0xffffff,0x000000);
	currentPos.x -= 8*size;
}

void fillRect(unsigned char * vram, int color, unsigned char w, unsigned char h){
	unsigned char * where = screenInfo->framebuffer + vram;
	int i, j;
	int pixelWidth = getBpp();
	for(i = 0; i < w; i++){
		for(j = 0; j < h;j++){
			where[j*pixelWidth] = color & 255;
			where[j*pixelWidth + 1] = (color >> 8) & 255;
			where[j*pixelWidth + 2] = (color >> 16) & 255;
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
	currentPos.x = 0;
	currentPos.y += 16*size;
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
	}
	currentPos.x = 0;
	currentPos.y = 0;
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