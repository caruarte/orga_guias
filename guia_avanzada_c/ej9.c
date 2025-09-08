#include <stdio.h>

void mayuscula(char *palabra){
    while(*palabra != '\0'){
        if (*palabra >= 97 && *palabra <= 122){
            *palabra -= 32;   
        }
        palabra++;
    }
    return;
}

int main(){
    char str1[] = "HolA MunDo";
    printf("%s\n", str1);
    mayuscula(str1);
    printf("%s\n", str1);
}