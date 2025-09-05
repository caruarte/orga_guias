#include <stdio.h>
#include <stdint.h>

int main(){
    int i = 10;
    while(i--){
        printf("i = %d\n", i);
    }
    // Son equivalentes
    for (int i = 10; i--;){
        printf("i = %d\n", i);
    }
}