#include <stdio.h>
#include <stdint.h>

int main(){
    uint32_t a[] = {1,2,3,4};
    for (int i = 0; i < sizeof(a)/sizeof(uint32_t) - 1; i++){
        uint32_t temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
    }
    for (int i = 0; i < sizeof(a)/sizeof(uint32_t); i++){
        printf("%d\n", a[i]);
    }

}