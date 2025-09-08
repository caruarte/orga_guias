#include <stdio.h>
#include <string.h>



int main(){
    char str1[] = "Hola Mundo";
    char str2[50];
    strcpy(str2, str1); //copiar str1 en str2
    printf("%s\n", str1);
    printf("%s\n", str2);

    strcat(str2, str1); // concatenar str1 en str2
    printf("%s\n", str1);
    printf("%s\n", str2);

    printf("%lu\n", strlen(str1)); // longitud de string

    if (strcmp(str1, str1) == 0) { // comparar, 0 si son iguales
        printf("Son iguales\n");
    }
}

// restrict sirve para decir que ese puntero es la unica forma de acceder a la memoria que apuntan,
// sirve para que dest y src no se superpongan