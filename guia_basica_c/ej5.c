#include <stdio.h>
#include <stdint.h>
int main() {
    float numF = 0.1;
    double numD = 0.1;
    printf("%f\n", numF);
    printf("%lf\n", numD);
    printf("%i\n", (int) numF);
    printf("%i\n", (int) numD);
    return 0;
}