#include <stdio.h>

// 역방향으로 더해서 세 번째 포인터가 나타내는 배열에 저장하는 함수
void addArrayReverse(int *a, int *b, int *result, int n) {
    // 반복문을 통해서 원하는 결과 값을 구한다
    for (int i = 0; i < n; ++i) {
        *(result + i) = *(a + i) + *(b + n - i - 1);
    }
}

int main() {
    // 필요한 변수를 선언하고 입력을 받는다
    int n;
    scanf("%d", &n);

    // 필요한 배열들을 선언을 해준다
    int a[n], b[n], result[n];
    int *p;

    // 반복문을 통해서 입력을 받는다
    for (p = a; p < a+n; p++) {
        scanf("%d", p);
    }

    // 반복문을 통해서 입력을 받는다
    for (p = b; p < b+n; p++) {
        scanf("%d", p);
    }

    // 함수에 입력을 하여 원하는 결과로 만든다
    addArrayReverse(a, b, result, n);

    // 반복문을 통해서 결과를 출력한다
    for (p = result; p < result+n; p++) {
        printf("%d", *p);
    }

    return 0;
}
