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
    while (start < end-1) {
        int *next = sel_next(start, end);
        printf("%d\n", number(start, next));
        start = next;
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
    int *initial = p;
    int increasing = 1;
    
    // p가 가리키는 원소부터 원소 값의 증가 또는 감소가
    // 끝나는 마지막 원소의 주소를 반환
    if (p >= end - 1) {
        return end - 1;
    }
    if (*p > *(p + 1)) {
        increasing = 0;
    }

    // 주소 증가를 시킨다
    p++;

    // 경향성이 끝나면 주소를 반환을 시켜준다
    while (p < end - 1) {
        if (increasing && *p > *(p + 1)) {
            return p;
        } else if (!increasing && *p < *(p + 1)) {
            return p;
        }
        p++;
    }

    // 원소들 경향성이 배열의 마지막에 도달하면, 배열
    // 의 마지막 원소의 주소를 반환한다.
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

