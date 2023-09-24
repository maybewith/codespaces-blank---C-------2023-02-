#include <stdio.h>

// 십진수 자릿수 표기: 천 THO 백 HUN 십 TEN (일자리에는 숫자만 출력)
char *position[] = {"", "THO", "HUN", "TEN", ""};

// 숫자 영어 표기: one two three four five six seven eight nine
char *number[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};


int main() {
    // 사용자로부터 정수 N을 입력을 받는다.
    int N;
    scanf("%d", &N);

    int idx = 4, digits[5] = {0}; // idx 값을 4로 초기화
    while (N) {
        digits[idx--] = N % 10; // 높은 자릿수부터 낮은 자릿수 순으로 배열에 저장
        N /= 10;
    }

    // 사용자로부터 정수 N을 입력받아 그 값을 표현하는 문자열로 출력
    for (int i = 0; i <= 4; i++) {
        if (digits[i]) {
            printf("%s %s ", number[digits[i]], position[i]);
        }
    }
    printf("\n");
    return 0;
}
