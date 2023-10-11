#include <stdio.h>
#include <string.h>

// 주어진 문자열에서 M 번째 단어를 찾습니다.
void getMthWord(char s[], char result[101], int M) {
    // 필요한 변수들을 선언한다.
    int start = 0, len = strlen(s);
    char word[101];
    int count = 0;

    // 반복문을 통해서 가장 짧은 것과 최대인 것에서
    // M 번째 단어를 구한다.
    for (int i = 0; i <= len; i++) {
        // 만약 단어의 끝 혹은 문자열의 끝에 도달하면
        if (s[i] == ' ' || s[i] == '\0') {
            strncpy(word, s + start, i - start);
            word[i - start] = '\0';
            start = i + 1;

            // 만약 찾은 문자라면 저장을 시킨다.
            if (count == M) {
                strcpy(result, word);
                return;
            }

            count++;
        }
    }
}

int main() {
    int N, M1, M2;
    // N 줄의 문자열과 M1, M2 값을 입력 받습니다.
    scanf("%d %d %d", &N, &M1, &M2);
    getchar();

    // 필요한 변수들을 선언한다.
    char str[N][101];
    int max_len = -1, min_len = 101;
    int max_idx = -1, min_idx = -1;

    // N 줄의 문자열을 입력 받습니다.
    for (int i = 0; i < N; i++) {
        gets(str[i]);

        // 가장 긴 문자열과 가장 짧은 문자열을 찾습니다.
        int len = strlen(str[i]);
        if (len < min_len) {
            min_len = len;
            min_idx = i;
        }
        if (len > max_len) {
            max_len = len;
            max_idx = i;
        }
    }

    char longest_word[101], shortest_word[101];
    // 가장 긴 문자열에서 M1번째 단어를 찾습니다.
    getMthWord(str[max_idx], longest_word, M1);
    // 가장 짧은 문자열에서 M2번째 단어를 찾습니다.
    getMthWord(str[min_idx], shortest_word, M2);

    char result[202];  // 합성된 결과를 위한 변수
    // 두 단어의 연결은 사전 순서상 빠른 단어 뒤에 순서가 늦은 단어를 연결합니다.
    if (strcmp(longest_word, shortest_word) < 0) {
        strcpy(result, longest_word);
        strcat(result, shortest_word);
    } else {
        strcpy(result, shortest_word);
        strcat(result, longest_word);
    }

    // 결과 출력
    printf("%s\n", str[max_idx]);  // 가장 긴 문자열 출력
    printf("%s\n", str[min_idx]);  // 가장 짧은 문자열 출력
    printf("%s\n", result);  // 합성된 단어 출력

    return 0;
}
