#include <stdio.h>
#include <string.h>

// 문장을 단어 단위로 분리하여 '이차원 배열'에 저장하는 함수
void splitWords(char *str, char words[21][21], int *count) {
    // 필요한 변수들을 선언하고 값을 입력한다.
    int len = strlen(str);
    int start = 0, j = 0;

    // 단어 단위로 반복문을 통해서 분리를 한다.
    for (int i = 0; i <= len; i++) {
        // 만약, 띄어쓰기 혹은 마지막 글자가 나온다면
        if (str[i] == ' ' || str[i] == '\0') {
            strncpy(words[*count], &str[start], i - start);
            words[*count][i - start] = '\0';
            (*count)++;
            start = i + 1;
        }
    }
}

// 문자열 정렬을 위한 문자열 비교 시 strcmp를 이용하는 함수
void sortWords(char words[21][21], int count) {
    char temp[21];
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            // 만약 앞 보다 크다면 다음과 같이 한다.
            if (strcmp(words[j], words[j + 1]) > 0) {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }
}

int main() {
    // 필요한 변수들을 선언을 한다.
    char str[201], words[21][21];
    int count = 0;

    // 문장을 입력받기 위해 gets 함수 사용
    gets(str);

    // 단어를 함수를 통해서 나눠준다.
    splitWords(str, words, &count);

    // 입력 문자열의 단어 출력
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }

    // 단어들을 함수를 통해서 정렬을 시킨다.
    sortWords(words, count);

    // 정렬된 단어 출력
    for (int i = 0; i < count; i++) {
        printf("%s", words[i]);
        if (i < count - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
