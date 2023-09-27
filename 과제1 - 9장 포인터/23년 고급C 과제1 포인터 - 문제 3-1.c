#include <stdio.h>

// PRT 함수 원형 선언을 한다.
void PRT(int n, char *p);

int main() {
    char str[100];  // ‘#’ 문자를 포함하여 최대 100개 문자가 입력되는 배열
    char *p = str;
    int longest = 0, current = 0;
    char *longest_word_start = NULL;
    char *current_word_start = NULL;

    // ‘#’ 문자가 입력될 때까지 문자를 입력받는다
    while ((*p = getchar()) != '#') {
        p++;
    }
    *p = '\0';

    // 배열을 훑으면서 가장 긴 단어와 그 시작 포인터를 찾는다
    for (p = str; *p != '\0'; p++) {
        if (*p >= 'a' && *p <= 'z') {  // 첫 글자는 항상 영어 소문자
            if (current == 0) {
                current_word_start = p;
            }
            current++;
        } else {
            // 제일 긴 것보다 길면 그것으로 다시 저장을 시킨다.
            if (current > longest) {
                longest = current;
                longest_word_start = current_word_start;
            }
            current = 0;
        }
    }

    // 마지막 단어가 가장 긴 단어인지 확인
    if (current > longest) {
        longest = current;
        longest_word_start = current_word_start;
    }

    // 소문자로 구성된 단어들을 출력
    for (p = str; *p != '\0';) {
        if (*p >= 'a' && *p <= 'z') {
            current = 0;
            // 만약 소문자이면 다음과 같이 한다.
            while (*p >= 'a' && *p <= 'z') {
                putchar(*p);
                p++;
                current++;
            }
            putchar('\n');
        } else {
            p++;
        }
    }

    // 길이가 가장 긴 단어의 길이를 출력
    printf("%d\n", longest);

    return 0;
}

// 단어들을 출력을 해주는 함수.
void PRT(int n, char *p) {
    for (int i = 0; i < n; i++) {
        putchar(*(p + i));
    }
    printf("\n");
}
