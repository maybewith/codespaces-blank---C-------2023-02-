#include <stdio.h>

int main() {
    int arr[5], rank[5];
    int *p, *q;

    // 5개의 정수 입력
    for (p = arr; p < arr + 5; p++) {
        scanf("%d", p);
    }

    // 등수 초기화
    for (p = rank; p < rank + 5; p++) {
        *p = 1;
    }

    // 등수 계산
    for (p = arr; p < arr + 5; p++) {
        for (q = arr; q < arr + 5; q++) {
            if (*p < *q) {
                rank[p - arr]++;
            }
        }
    }

    // 결과 출력
    for (p = arr, q = rank; p < arr + 5; p++, q++) {
        printf("%d=r%d ", *p, *q);
    }
    printf("\n");

    return 0;
}
