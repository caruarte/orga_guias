#include <stdio.h>
#include <stdint.h>
int main() {
    printf("int 8 bits: %lu \n", sizeof(int8_t));
    printf("int 16 bits: %lu \n", sizeof(int16_t));
    printf("int 32 bits: %lu \n", sizeof(int32_t));
    printf("int 64 bits: %lu \n", sizeof(int64_t));
    
    printf("int 8 bits unsigned: %lu \n", sizeof(uint8_t));
    printf("int 16 bits unsigned: %lu \n", sizeof(uint16_t));
    printf("int 32 bits unsigned: %lu \n", sizeof(uint32_t));
    printf("int 64 bits unsigned: %lu \n", sizeof(uint64_t));
    return 0;
}