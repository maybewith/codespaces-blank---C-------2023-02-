#include <stdio.h>
#include <stdlib.h>

int compare_asc(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int compare_desc(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main() {
    int a[100], *p;
    int N;
    int count = 0;

    scanf("%d", &N);

    int m = 0;
    for (p = a; m < N; m++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp > 0) {
            *p = tmp;
            p++;
            count++;
        }
    }

    printf("%d\n", count); // 배열에 저장된 정수의 개수 출력

    // 배열 정렬
    if (count % 2 == 1) {
        qsort(a, count, sizeof(int), compare_asc);
    } else {
        qsort(a, count, sizeof(int), compare_desc);
    }

    // 정렬된 배열 출력
    for (p = a; p < a + count; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    // 연속적인 홀수의 최대 횟수 계산
    int max_consecutive_odd = 0;
    int current_consecutive_odd = 0;
    for (p = a; p < a + count; p++) {
        if (*p % 2 == 1) {
            current_consecutive_odd++;
            if (current_consecutive_odd > max_consecutive_odd) {
                max_consecutive_odd = current_consecutive_odd;
            }
        } else {
            current_consecutive_odd = 0;
        }
    }
    printf("%d\n", max_consecutive_odd); // 최대 횟수 출력

    return 0;
}
