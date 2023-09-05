#include <stdio.h>

void gcdlcm(int a, int b, int *gcd, int *lcm) {
    int temp, originalA = a, originalB = b;
    
    // Calculate GCD
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    *gcd = a;
    
    // Calculate LCM
    *lcm = (originalA * originalB) / *gcd;
}

int main() {
    int a, b, gcd, lcm;
    
    scanf("%d %d", &a, &b);
    
    gcdlcm(a, b, &gcd, &lcm);
    
    printf("%d %d", gcd, lcm);
    return 0;
}
