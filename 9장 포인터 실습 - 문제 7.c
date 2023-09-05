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
    int x, y, z;
    input(&x, &y, &z);
    output(&x, &y, &z);
    return 0;
}
