#include <stdio.h>

int arrsum(int *start, int *end) {
    int sum = 0;
    for (int *p = start; p <= end; ++p) {
        sum += *p;
    }
    return sum;
}

int main() {
    int N, S, E;
    scanf("%d", &N);
    scanf("%d %d", &S, &E);

    int arr[100];
    for (int i = 0; i < N; ++i) {
        scanf("%d", arr + i);
    }

    

    
    int sum = arrsum(arr + S, arr + E);
    printf("%d\n", sum);
    

    return 0;
}
