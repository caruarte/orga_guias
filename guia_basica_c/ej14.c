#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int i = 0; // se inicialia en 0 por ser global

int main(){
    int i = 5; // la variable local oculta a la global
    printf("%d\n", i);
    printf("%d\n", i);
}