#include <stdio.h>

void ABC(int *start, int length) {
    int *p, *q, temp;
    for (p = start; p < start + length - 1; p++) {
        for (q = p + 1; q < start + length; q++) {
            if (*p < *q) {
                temp = *p;
                *p = *q;
                *q = temp;
            }
        }
    }
}

int main() {
    int arr[10];
    int *p;

    for (p = arr; p < arr + 10; p++) {
        scanf("%d", p);
    }

    for (int i = 10; i >= 2; i--) {
        ABC(arr, i);
    }

    for (p = arr; p < arr + 10; p++) {
        printf("%d ", *p);
    }

    printf("\n");
    return 0;
}
