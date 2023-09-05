#include <stdio.h>

int add_to_k(int *start, int *end) {
    int sum = 0;
    int *p;
    for (p = start; p <= end; p++) {
        sum += *p;
    }
    return sum;
}

int main() {
    int N;
    scanf("%d", &N);

    int d[100];
    int *p;

    for (p = d; p < d + N; p++) {
        scanf("%d", p);
    }

    int sum = 0;
    for (p = d; p < d + N; p++) {
        sum += add_to_k(d, p);
    }

    printf("%d\n", sum);
    return 0;
}
