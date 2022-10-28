#include <syscallslib.h>
void shell(){
    sys_write(0,"shell",6);
}