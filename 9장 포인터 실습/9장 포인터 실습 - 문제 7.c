#include <stdio.h>

// 세 정수를 입력받는 함수
void input(int *x, int *y, int *z) {
    scanf("%d %d %d", x, y, z);
}

// 세 정수를 출력하는 함수
void output(int *x, int *y, int *z) {
    printf("%d %d %d\n", *x, *y, *z);
}

int main() {
    // 필요한 변수 선언
    int x, y, z;

    // 입력을 받는 함수
    input(&x, &y, &z);

    // 출력을 하는 함수
    output(&x, &y, &z);
    
    return 0;
}
