#include <stdio.h>
#include <string.h>

// 함수는 주어진 문자열에서 사전적으로 가장 빠른 단어와 가장 늦은 단어를 찾습니다.
void find_words(char s[], char earliest[101], char latest[101]) {
    // 필요한 변수를 선언한다.
    int start = 0, len = strlen(s);
    char word[101];

    strcpy(earliest, s);  // 초기화를 위해 전체 문자열로 설정
    strcpy(latest, "");   // 빈 문자열로 초기화

    // 필요한 단어를 반복문을 통해서 찾는다.
    for (int i = 0; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            strncpy(word, s + start, i - start);
            word[i - start] = '\0';
            start = i + 1;

            // 최소보다 짧으면 그것을 최소로 저장한다.
            if (strcmp(word, earliest) < 0) {
                strcpy(earliest, word);
            }
            // 최대보다 크다면 그것을 최대로 다시 설정을 한다.
            if (strcmp(word, latest) > 0) {
                strcpy(latest, word);
            }
        }
    }
}

int main() {
    // 필요한 변수들을 선언을 한다.
    int N;
    char shortest[101], longest[101];
    int min_len = 101, max_len = -1;

    // 입력을 받는다.
    scanf("%d", &N);
    getchar();  // 정수 N 입력 후, getchar( ) 사용

    // 반복문을 통해서 문자열을 입력받고 문제를 해결한다.
    for (int i = 0; i < N; i++) {
        char str[101];
        gets(str);  // 문자열 입력 시 gets 사용

        // 길이를 구하고 최소보다 짧으면 그것을 최소로 저장한다.
        int len = strlen(str);
        if (len < min_len) {
            strcpy(shortest, str);
            min_len = len;
        }
        // 최대보다 크다면 그것을 최대로 다시 설정을 한다.
        if (len > max_len) {
            strcpy(longest, str);
            max_len = len;
        }
    }

    char shortest_word[101], longest_word[101];
    // 가장 짧은 문자열에서 사전적 순서가 가장 빠른 단어를 찾습니다.
    find_words(shortest, shortest_word, longest_word);
    printf("%s ", shortest_word);
    
    // 가장 긴 문자열에서 사전적 순서가 가장 늦은 단어를 찾습니다.
    find_words(longest, shortest_word, longest_word);
    printf("%s\n", longest_word);

    return 0;
}
