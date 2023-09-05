#include <stdio.h>

int main() {
    int ar[50];
    int *p = ar;
    int N, count = 0;

    scanf("%d", &N);
    for (p = ar; p < ar + N; p++) {
        scanf("%d", p);
        if (*p == 0) break;
        count++;
    }

    printf("%d\n", count);
    return 0;
}
