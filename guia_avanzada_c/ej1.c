#include <stdio.h>

typedef struct {
    char* nombre;
    int vida;
    double ataque;
    double defensa;
} monstruo_t;

int main() {
    monstruo_t monstruos[] = {{"Vampiro", 10, 5, 2}, {"Hombre Lobo", 15, 4, 7}};

    for (int i = 0; i < sizeof(monstruos)/ sizeof(monstruos[0]); i++){
        printf("%s, %d\n", monstruos[i].nombre, monstruos[i].vida); 
    }

}