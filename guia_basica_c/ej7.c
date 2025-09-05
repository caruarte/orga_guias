#include <stdio.h>
int main(){
    int a = 5, b = 3, c = 2, d = 1;
    printf("%X\n", a+b*c/d); // el %x es para que sea hexadecimal.
    printf("%x\n", a%b);
    printf("%x\n", a==b);
    printf("%x\n", a!=b);
    printf("%x\n", a&b);
    printf("%x\n", a|b);
    printf("%x\n", ~a);
    printf("%x\n", a && b);
    printf("%x\n", a || b);
    printf("%x\n", a << b);
    printf("%x\n", a >> b);
    printf("%x\n", a += b);
    printf("%x\n", a -= b);
    printf("%x\n", a *= b);
    printf("%x\n", a /= b);
    printf("%x\n", a %= b);

}