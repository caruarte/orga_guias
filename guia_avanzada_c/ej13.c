#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct{
    char *nombre;
    int edad;
} persona_t;

persona_t *crearPersona(char *nombre, int edad){
    persona_t *persona = malloc(sizeof(persona_t));
    persona -> nombre = nombre;
    persona -> edad = edad;
    return persona;
}

void eliminarPersona(persona_t *persona){
    free(persona);
    return;
}

int main(){
    persona_t *persona = crearPersona("Cesar", 20);
    printf("%s\n", persona -> nombre);
    printf("%d\n", persona -> edad);
    eliminarPersona(persona);
    printf("%s\n", persona -> nombre); // error
    printf("%d\n", persona -> edad);
    return 0;
}