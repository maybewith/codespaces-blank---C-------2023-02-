#include <stdio.h>

// 배열의 합을 구하는 함수
int arrsum(int *start, int *end) {
    // 총 합을 기억할 변수
    int sum = 0;

    // 반복문을 통해서 총합을 구한다
    for (int *p = start; p <= end; ++p) {
        sum += *p;
    }

    // 결과를 반환한다
    return sum;
}

int main() {
    // 필요한 변수를 선언한다
    int N, S, E;

    // 입력들을 받는다
    scanf("%d", &N);
    scanf("%d %d", &S, &E);

    // 배열을 선언하고 입력을 받는다
    int arr[100];
    for (int i = 0; i < N; ++i) {
        scanf("%d", arr + i);
    }

    // 배열의 합을 함수에 넣어서 구해서 저장을 시킨다    
    int sum = arrsum(arr + S, arr + E);

    // 결과를 출력을 해준다
    printf("%d\n", sum);
    
    return 0;
}
