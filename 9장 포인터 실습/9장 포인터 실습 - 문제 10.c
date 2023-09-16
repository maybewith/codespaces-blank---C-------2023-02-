#include <stdio.h>

// 최대 공약수와 최소 공배수를 구해주는 함수
void gcdlcm(int a, int b, int *gcd, int *lcm) {
    int temp, originalA = a, originalB = b;
    
    // 최대 공약수를 반복문을 통해서 구하자
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }

    // 최대 공약수를 포인터에 저장시킨다
    *gcd = a;
    
    // 최소 공배수를 구해준다
    *lcm = (originalA * originalB) / *gcd;
}

int main() {
    // 필요한 변수들을 선언을 해준다
    int a, b, gcd, lcm;
    
    // 입력을 받는다
    scanf("%d %d", &a, &b);
    
    // 함수를 통해서 최대 공약수와 최소 공배수를 구한다
    gcdlcm(a, b, &gcd, &lcm);
    
    // 결과를 출력을 한다
    printf("%d %d", gcd, lcm);
    
    return 0;
}
