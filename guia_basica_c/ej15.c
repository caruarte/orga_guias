#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int factorial(int n);

int main(){
    int num = 5;
    int res = factorial(num);
    printf("%d\n", res);
}

int factorial(int n){
    if (n == 0){
        return 1;
    }
    return n * factorial(n-1);
}