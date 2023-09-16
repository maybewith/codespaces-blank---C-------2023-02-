#include <stdio.h>

int input(int *p);
int *sel_next(int *p, int N, int M);
int number(int *p, int *q);

int main() {
    // 필요한 변수들과 포인터를 선언한다
    int x[100];
    int N, M;
    int *end;
    
    // 입력을 받을 함수를 호출한다. M도 입력을 받는다
    N = input(x);
    scanf("%d", &M);
    
    // 10을 초과하기 전의 주소를 함수 호출을 통해서 알아낸다
    end = sel_next(x, N, M);

    // 결과를 하나의 정수로 모아 출력을 한다
    printf("%d\n", number(x + M, end));
    
    return 0;
}

// 함수 원형: int input(int *p)
int input(int *p) {

    // 배열 x의 시작 주소를 인자로 받아 종료 조건까지 정수를 입력받기
    int count = 0;
    while (1) {
        // 입력을 받고 종료조건이면 종료를 한다.
        scanf("%d", p + count);
        if (*(p + count) == -1) break;
        count++;
    }

    //  배열 원소의 개수를 반환한다
    return count;
}

// 함수 원형: int *sel_next(int *p, int N, int M)
int *sel_next(int *p, int N, int M) {
    // 합을 기억할 변수와 배열을 기억할 포인터를 선언
    int sum = 0;
    int *end;
    
    // 원소 들의 합이 10을 초과하기 바로 전의 원소의 주소를 반환
    for (end = p + M; end < p + N; ++end) {
        sum += *end;

        // 10을 초과할 경우
        if (sum > 10) {
            return end - 1;
        }
    }

    // 바로 전의 원소의 주소를 반환
    return end - 1;
}

// 함수 원형: int number(int *p, int *q)
int number(int *p, int *q) {
    // x[M]의 위치와 sel_next에서 반환된 위치를 인자로 받아
    // 두 포인터 사이의 한 자리 정수를 모아
    int num = 0;
    for (int *k=p; k <= q; ++k) {
        num = num * 10 + *k;
    }

    // 하나의 정수로 만들어 반환
    return num;
}
