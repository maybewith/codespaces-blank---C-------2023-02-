#include <stdio.h>
#include <string.h>

int main() {
    // 문자열A와 문자열B 초기화
    char stringA[101], stringB[101], finalResult[251] = "";

    // 문자열A에서 추출한 단어를 저장할 배열
    char wordsInA[101][11];  
    int i, j, countOfWordsA = 0, replacementIndex = 0;

    // 문자열A와 문자열B 입력 받기
    gets(stringA);
    gets(stringB);

    // strtok를 사용하지 않고 문자열A를 단어로 분할
    char *start = stringA, *end = stringA;
    while (*end != '\0') {
        if (*end == ' ' || *(end + 1) == '\0') {
            if (*end == ' ') {
                *end = '\0';
            }
            strcpy(wordsInA[countOfWordsA++], start);
            start = end + 1;
        }
        end++;
    }

    // 문자열A 내의 단어를 확인하며 중복 단어가 있는지 조사한다.
    for (i = 0; i < countOfWordsA; i++) {
        int isDuplicate = 0;

        // 현재 단어가 이전에 나타났는지 확인
        for (j = 0; j < i; j++) {
            if (strcmp(wordsInA[j], wordsInA[i]) == 0) {
                isDuplicate = 1;
                break;
            }
        }

        if (isDuplicate) {
            // 중복된 경우, 문자열B에서 아직 사용하지 않은 단어로 치환한다.
            char replacementWord[11];
            int k = 0;
            while (stringB[replacementIndex] != ' ' && stringB[replacementIndex] != '\0') {
                replacementWord[k++] = stringB[replacementIndex++];
            }
            replacementWord[k] = '\0';
            // 공백 또는 문자열의 끝 건너뛰기
            replacementIndex++;  

            strcat(finalResult, replacementWord);
        } else {
            // 중복되지 않은 경우, 원래 단어를 결과 문자열에 추가
            strcat(finalResult, wordsInA[i]);  
        }

        // 단어와 단어 사이에 공백 추가
        strcat(finalResult, " ");
    }

    // 마지막 결과 문자열의 끝부분의 공백을 제거한다.
    finalResult[strlen(finalResult) - 1] = '\0';
    // 치환된 결과 문자열 출력
    printf("%s\n", finalResult);

    return 0;
}
