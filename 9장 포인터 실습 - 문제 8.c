#include <stdio.h>

// 두 정수의 값을 교환하는 함수
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int N, a, b;
    int arr[50];
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    scanf("%d %d", &a, &b);
    swap(&arr[a], &arr[b]);
    for (int i = 0; i < N; ++i) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
