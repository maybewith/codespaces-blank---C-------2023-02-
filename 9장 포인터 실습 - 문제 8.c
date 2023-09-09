#include <stdio.h>

// 두 정수의 값을 교환하는 함수
void swap(int *a, int *b) {
    // 임의의 변수를 활용하여 값을 교환시킨다
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // 필요한 변수와 배열을 선언을 한다
    int N, a, b;
    int arr[50];

    // 개수를 입력을 받는다
    scanf("%d", &N);

    // 반복문을 통해서 배열에 필요한 것들을 입력을 받는다
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }

    // 추가로 입력을 받는다
    scanf("%d %d", &a, &b);

    // 변수를 바꿔준다
    swap(&arr[a], &arr[b]);

    // 반복문을 통해서 출력을 한다
    for (int i = 0; i < N; ++i) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
