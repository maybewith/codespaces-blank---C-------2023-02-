#include <stdio.h>

int input(int *p);
int *sel_next(int *p, int *end);
int number(int *p, int *q);

int main() {
    // 필요한 변수들과 포인터를 선언한다
    int x[100];
    int N;
    int *start, *end;
    
    // 입력을 받을 함수를 호출한다. 시작과 끝 주소를 포인터에 저장한다
    N = input(x);
    start = x;
    end = x + N;
    
    // 반복문으로 시작부터 끝까지 돌린다
    while (start < end) {
        int *next = sel_next(start, end);
        printf("%d*", number(start, next));
        start = next + 1;
    }
    
    printf("\n");
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

// 함수 원형: int *sel_next(int *p)
int *sel_next(int *p, int *end) {
    // 원소들의 합을 기억하는 변수
    int sum = 0;

    // 원소들의 합이 10을 초과하기 바로 전 원소의 주소를 반환
    while (p < end) {
        sum += *p;

        // 원소들의 합이 10을 초과할 때
        if (sum > 10) {
            // 그 전의 주소를 반환을 시켜준다
            return p - 1;
        }

        // 주소 증가 시킨다
        p++;
    }

    // 원소들의 합이 10을 초과하지 않은 채 배열의 마지막에 도달하면, 배열
    // 의 마지막 원소의 주소를 반환한다. 
    return p - 1;
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
