#include <stdio.h>
#include <stdint.h>

uint16_t *secuencia(uint16_t n){
    uint16_t arr[n];
    for(uint16_t i = 0; i < n; i++){
        arr[i] = i;}
    return arr; // arr es una variable automatica, se libera al salir de la funcion
}


int main(){
    uint16_t *arr = secuencia(10); // apunta a una dirección de memoria inválida
    printf("%d\n", arr[0]); 
    return 0;
}