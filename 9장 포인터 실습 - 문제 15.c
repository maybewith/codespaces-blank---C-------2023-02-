#include <stdio.h>

// 배열에서 조사 대상의 첫 번째 정수부터 마지막 정수(즉, 9번째 정수)중 가장 큰 정수를 찾고, 
// 이를 첫 번째 위치의 정수와 교환하는 함수
void ABC(int *start, int length) {
    // 필요한 변수들을 선언한다
    int *p, *q, temp;

    // 반복문을 통해서 앞으로 갈 숫자들을 앞으로 보낸다
    for (p = start; p < start + length - 1; p++) {
        for (q = p + 1; q < start + length; q++) {
            // 조건문으로 비교를 하여 순서를 바꾼다
            if (*p < *q) {
                temp = *p;
                *p = *q;
                *q = temp;
            }
        }
    }
}

int main() {
    // 필요한 배열과 포인터를 선언한다
    int arr[10];
    int *p;

    // 반복문을 통해서 입력을 받는다
    for (p = arr; p < arr + 10; p++) {
        scanf("%d", p);
    }

    // 함수를 호출을 하여 순서대로 배열을 정렬시킨다
    for (int i = 10; i >= 2; i--) {
        ABC(arr, i);
    }

    // 결과를 반복문을 통해서 출력을 한다
    for (p = arr; p < arr + 10; p++) {
        printf("%d ", *p);
    }

    return 0;
}
