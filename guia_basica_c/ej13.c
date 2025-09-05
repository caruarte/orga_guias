#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // para que no se generen los mismos numeros
    uint32_t dado[] = {1,2,3,4,5,6};
    uint32_t veces[] = {0,0,0,0,0,0};
    for (int i = 0; i < 60000000; i++){ 
        uint32_t random = rand() % 6;
        veces[random]++;
    }
    printf("Veces que salio 1: %d\n", veces[0]);
    printf("Veces que salio 2: %d\n", veces[1]);
    printf("Veces que salio 3: %d\n", veces[2]);
    printf("Veces que salio 4: %d\n", veces[3]);
    printf("Veces que salio 5: %d\n", veces[4]);
    printf("Veces que salio 6: %d\n", veces[5]);
}