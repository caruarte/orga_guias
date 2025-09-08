#include <stdio.h>

int main(){
    char *str1 = "Hola"; // apunta a literal de cadena en memoria de solo lectura, no modificable
    char str2[] = "Hola"; // se reserva array de 5 chars en el stack, es modificable
    printf("%s\n", str1);
    printf("%s\n", str2);
}