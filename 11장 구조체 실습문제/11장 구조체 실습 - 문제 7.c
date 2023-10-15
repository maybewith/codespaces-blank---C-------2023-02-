#include <stdio.h>

// 숫자의 구조체를 만들어준다.
struct Number{
    int value;
    int rank;
};

// 그 정수의 내림차순 상 순위를 계산하여, 순위를 반환한다. 
int getRank(struct Number numbers[], int idx) {
    int rank = 1;
    for (int i = 0; i < 10; i++) {
        if (i != idx && numbers[i].value > numbers[idx].value) {
            rank++;
        }
    }

    // 순위를 반환한다.
    return rank;
}

int main() {
    // 10개의 정수와 순위를 저장할 구조체 배열
    struct Number numbers[10]; 

    // 10개의 정수 입력 받기
    for (int i = 0; i < 10; i++) {
        scanf("%d", &numbers[i].value);
        numbers[i].rank = 0;  // 초기화
    }

    // 각 정수의 순위 계산 후 구조체 배열에 저장
    for (int i = 0; i < 10; i++) {
        numbers[i].rank = getRank(numbers, i);
    }

    // 3번째와 7번째 순위에 해당하는 정수 찾기
    int thirdValue = 0, seventhValue = 0;
    for (int i = 0; i < 10; i++) {
        if (numbers[i].rank == 3) thirdValue = numbers[i].value;
        if (numbers[i].rank == 7) seventhValue = numbers[i].value;
    }

    // 3번째 순위와 7번째 순위에 해당하는 정수를 출력한다.
    printf("%d %d\n", thirdValue, seventhValue);

    return 0;
}
