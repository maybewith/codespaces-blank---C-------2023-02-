#include <stdio.h>
#include <string.h>

// 문자열 치환 함수 원형 선언
void replaceSubstring(char *original, char *substr, char *replacement);

int main() {
    char strA[101];       // 문자열A: 주어진 문자열
    char strB[11];        // 문자열B: 치환될 문자열
    char strC[11];        // 문자열C: 치환할 문자열

    // 문자열A, B, C를 차례대로 입력받는다.
    gets(strA);
    gets(strB);
    gets(strC);

    // 문자열A에서 문자열B를 문자열C로 치환하는 함수 호출
    replaceSubstring(strA, strB, strC);

    // 치환된 문자열 출력
    printf("%s\n", strA);

    return 0;
}

// 구현한 문자열 탐색 함수
char *my_strstr(char *original, char *substr) {
    int len1 = strlen(original);
    int len2 = strlen(substr);
    for (int i = 0; i <= len1 - len2; i++) {
        if (strncmp(&original[i], substr, len2) == 0) {
            return &original[i];
        }
    }
    return NULL;
}

// 문자열 치환 함수
void replaceSubstring(char *original, char *substr, char *replacement) {
    // 필요한 변수들을 선언한다.
    char buffer[251] = "";
    char *insert_point = buffer;
    char *tmp = original;
    int substr_length = strlen(substr);
    int replacement_length = strlen(replacement);

    // 문자열 내에서 substr 찾기
    while (1) {
        char *p = my_strstr(tmp, substr);

        // substr을 찾지 못하면 남은 부분 복사하고 break
        if (p == NULL) {
            strcpy(insert_point, tmp);
            break;
        }

        // substr 앞까지 복사
        strncpy(insert_point, tmp, p - tmp);
        insert_point += p - tmp;

        // replacement 복사
        strncpy(insert_point, replacement, replacement_length);
        insert_point += replacement_length;

        // 다음 검색 위치로 이동
        tmp = p + substr_length;
    }

    // 원본 문자열에 결과 복사
    strcpy(original, buffer);
}

