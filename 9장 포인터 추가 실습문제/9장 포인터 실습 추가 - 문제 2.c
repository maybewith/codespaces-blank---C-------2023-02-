#include <stdio.h>

// 작은 수부터 큰 수까지 오름차순
void ABCO(int *start, int length) {
    // 필요한 변수들을 선언한다
    int *p, *q, temp;

    // 반복문을 통해서 앞으로 갈 숫자들을 앞으로 보낸다
    for (p = start; p < start + length - 1; p++) {
        for (q = p + 1; q < start + length; q++) {
            // 조건문으로 비교를 하여 순서를 바꾼다
            if (*p > *q) {
                temp = *p;
                *p = *q;
                *q = temp;
            }
        }
    }
}

// 큰 수부터 작은 수까지 내림차순
void ABCE(int *start, int length) {
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
    // 포인터를 통해서 배열을 훑어본다
    int a[100], *p;

    // 입력을 받을 숫자의 개수와 양수의 개수를 저장하는 변수
    int N;
    int count = 0;

    // N개의 정수를 입력받는다
    scanf("%d", &N);

    // 0보다 큰 정수만 배열에 저장한다
    int m = 0;
    for (p = a; m < N; m++) {

        // 입력을 받는다
        int tmp;
        scanf("%d", &tmp);

        // 양수이면 입력을 받는다
        if (tmp > 0) {
            *p = tmp;
            p++;

            // 저장된 개수를 센다
            count++;
        }
    }

    // 배열에 저장된 정수의 개수 출력
    printf("%d\n", count); 

    // 배열 정렬
    if (count % 2 == 1) {
        // 배열에 저장된 정수의 개수가 홀수이면, 배열에 저장된 정수를 작은 수부터 큰 수까지 오름차순으로
        // 정렬하여 출력한다
        ABCO(a, count);
    } else {
        // 배열에 저장된 정수의 개수가 짝수이면, 배열에 저장된 정수를 큰 수부터 작은 수까지 내림차순으로
        // 정렬하여 출력한다
        ABCE(a, count);
    }

    // 정렬된 배열 출력
    for (p = a; p < a + count; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    // 정렬된 배열에서 홀수가 연속해서 나오는 횟수를 세어서
    // 이 중 최대 횟수를 출력한다.
    int max_consecutive_odd = 0;
    int current_consecutive_odd = 0;
    for (p = a; p < a + count; p++) {
        // 홀수가 연속해서 나온다는 것을 센다
        if (*p % 2 == 1) {
            current_consecutive_odd++;
            if (current_consecutive_odd > max_consecutive_odd) {
                max_consecutive_odd = current_consecutive_odd;
            }
        } else {
            // 연속이 아니기에 초기화
            current_consecutive_odd = 0;
        }
    }

    // 최대 횟수 출력
    printf("%d\n", max_consecutive_odd); 

    return 0;
}
