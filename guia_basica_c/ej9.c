#include <stdio.h>
#include <stdint.h>
int main(){
    uint32_t a = 0xa0000000;
    uint32_t b = 0x00000005;
    if ((a >> 29) == (b & 0x7)){
        printf("Son iguales los tres bits mas altos de a y los 3 mas bajos de b\n");
    }
}