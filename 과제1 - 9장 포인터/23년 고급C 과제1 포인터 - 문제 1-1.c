#include <stdio.h>
#include <stdlib.h>

// 함수 원형 선언
int* MAX(int* ar);
int* MIN(int* ar);

int main() {
    // 입력될 줄 수에 해당하는 정수 N을 입력받는다.
    int N;
    int ar[100]={0,};
    int size, *maxValue, *minValue;
    int *p;

    // N 값 입력
    scanf("%d", &N);

    // 아래 과정을 N번 반복한다.
    while (N--) {
        size = 0;

        // 배열에 정수 입력
        for(p = ar; ; p++) {
            scanf("%d", p);
            if (*p == 0) break;
            size++;
        }

        // MAX, MIN 함수 호출
        maxValue = MAX(ar);
        minValue = MIN(ar);

        // 결과 출력
        printf("%d %d\n", *maxValue, *minValue);

        // 문제 1-2: 입력된 순서상 최대값과 최소값 사이에 위치한 정수 출력
        

    }

    return 0;
}

// MAX 함수 구현
// 인자: int형 배열 ar
int* MAX(int* ar) {
    int* maxPtr = ar;
    int* p;
    for (p = ar + 1; *p !=0; p++) {
        if (*p > *maxPtr) {
            maxPtr = p;
        }
    }

    // 반환 값: int형 포인터 즉 주소
    return maxPtr;
}

// MIN 함수 구현
// 인자: int형 배열 ar
int* MIN(int* ar) {
    int* minPtr = ar;
    int* p;
    for (p = ar + 1; *p !=0; p++) {
        if (*p < *minPtr) {
            minPtr = p;
        }
    }
    return minPtr;
}
