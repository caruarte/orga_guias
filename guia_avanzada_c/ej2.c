#include <stdio.h>

typedef struct {
    char* nombre;
    int vida;
    double ataque;
    double defensa;
} monstruo_t;

monstruo_t evolution(monstruo_t monstruo){
    monstruo.ataque = monstruo.ataque + 10;
    monstruo.defensa = monstruo.defensa + 10;
    return monstruo;
}

int main() {
    monstruo_t monstruo = {"Vampiro", 10, 5, 7};

    printf("%s, %d, %lf, %lf\n", monstruo.nombre, monstruo.vida, monstruo.ataque, monstruo.defensa);

    monstruo = evolution(monstruo);

    printf("%s, %d, %lf, %lf\n", monstruo.nombre, monstruo.vida, monstruo.ataque, monstruo.defensa);

}