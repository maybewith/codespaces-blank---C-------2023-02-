#include <stdio.h>

// 첫 번째 포인터가 가리키는 배열의 원소부터 두 번째 포인터가 가리키는 배열의 원소까지, 
// 배열의 원소 값을 더한 합을 계산하는 함수
int add_to_k(int *start, int *end) {
    int sum = 0;
    int *p;
    for (p = start; p <= end; p++) {
        sum += *p;
    }

    // 결과를 반환한다
    return sum;
}

int main() {
    // 필요한 변수를 선언하고 입력을 받는다
    int N;
    scanf("%d", &N);

    // 배열과 포인터를 선언을 해준다
    int d[100];
    int *p;

    // 배열의 입력을 반복문을 통해서 입력 받는다
    for (p = d; p < d + N; p++) {
        scanf("%d", p);
    }

    // 합을 구하기 위해서 반복문과 함수를 사용한다
    int sum = 0;
    for (p = d; p < d + N; p++) {
        sum += add_to_k(d, p);
    }

    // 결과를 출력을 한다
    printf("%d\n", sum);

    return 0;
}
