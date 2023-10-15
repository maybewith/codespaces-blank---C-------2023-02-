#include <stdio.h>

// 복소수를 표현하는 complex 구조체를 정의하여 사용하시오.
struct complex{
    // 실수부를 나타내는 실수형 변수
    float real;

    // 허수부를 나타내는 실수형 변수
    float imag;
};

// 인자: 두 개의 complex 구조체
struct complex add(struct complex a, struct complex b) {
    struct complex result;

    // 실수와 허수 각각 계산하기
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;

    // 반환 값: complex 구조체
    return result;
}

int main() {
    // 복소수를 저장할 complex 구조체 변수 선언
    struct complex c1, c2, result;
    
    // 복소수 2개를 사용자로부터 입력 받기
    scanf("%f %f", &c1.real, &c1.imag);
    scanf("%f %f", &c2.real, &c2.imag);

    // add 함수를 호출하여, 입력 받은 두 복소수의 합 구하기
    result = add(c1, c2);

    // 결과값으로, 입력 받은 두 복소수의 합, 소수점 이하 첫째자리까지 출력하기
    printf("%.1f + %.1fi", result.real, result.imag);

    return 0;
}
