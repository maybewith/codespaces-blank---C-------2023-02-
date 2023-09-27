#include <stdio.h>
#include <stdlib.h>

// 함수 원형 선언
int* MAX(int* ar);
int* MIN(int* ar);

int main() {
    int N;
    int ar[100] = {0,};
    int *p, *maxPtr, *minPtr, *tempPtr;

    // 사용자로부터 정수 N 입력 받기
    scanf("%d", &N);

    while(N--) {
        // 사용자로부터 정수 입력 받기 (0이 입력될 때까지)
        for(p = ar; ; p++) {
            scanf("%d", p);
            if (*p == 0) break;
        }

        // MAX, MIN 함수 호출하여 최대값, 최소값의 주소를 받아온다.
        maxPtr = MAX(ar);
        minPtr = MIN(ar);

        // 최대값, 최소값의 주소 순서를 확인하여 재배열한다.
        if(maxPtr > minPtr) {
            tempPtr = maxPtr;
            maxPtr = minPtr;
            minPtr = tempPtr;
        }

        // 최대값과 최소값 사이에 있는 정수 출력
        int found = 0; // 출력할 정수가 있는지 체크
        for(p = maxPtr + 1; p < minPtr; p++) {
            printf("%d ", *p);
            found = 1;
        }
        if (!found) printf("none");
        printf("\n");
    }

    return 0;
}

// MAX 함수: 배열에서 최대값의 주소 반환
int* MAX(int* ar) {
    int* maxPtr = ar;
    for(int* p = ar + 1; *p != 0; p++) {
        if(*p > *maxPtr) {
            maxPtr = p;
        }
    }
    return maxPtr;
}

// MIN 함수: 배열에서 최소값의 주소 반환
int* MIN(int* ar) {
    int* minPtr = ar;
    for(int* p = ar + 1; *p != 0; p++) {
        if(*p < *minPtr) {
            minPtr = p;
        }
    }
    return minPtr;
}
