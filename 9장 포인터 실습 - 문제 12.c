#include <stdio.h>

void addArrayReverse(int *a, int *b, int *result, int n) {
    for (int i = 0; i < n; ++i) {
        *(result + i) = *(a + i) + *(b + n - i - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n], b[n], result[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }

    addArrayReverse(a, b, result, n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
