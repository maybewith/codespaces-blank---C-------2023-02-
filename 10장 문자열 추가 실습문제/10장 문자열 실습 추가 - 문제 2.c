#include <stdio.h>
#include <string.h>

int main() {
    int M, N;
    // 입력받은 문자열의 최대 길이는 100이고, 각 문자열에 포함된 단어의 최대 개수는 20 이다.
    char str1[101], str2[101], words1[21][21], words2[21][21], finalWord[42];

    // 필요한 값들을 입력을 받는다.
    scanf("%d %d", &M, &N);
    getchar();

    // 문자열을 입력을 받는다.
    gets(str1);
    gets(str2);

    // 첫 번째 단어의 위치는 0번부터 시작한다.
    int count1 = 0, start1 = 0;
    for (int i = 0; i < strlen(str1); i++) {
        if (str1[i] == ' ' || str1[i + 1] == '\0') {
            // 공백을 포함하는 두 개의 문자열 str1과 str2를 입력받아
            if (str1[i + 1] == '\0') {
                strncpy(words1[count1], &str1[start1], i - start1 + 1);
                words1[count1][i - start1 + 1] = '\0';
            } else {
                strncpy(words1[count1], &str1[start1], i - start1);
                words1[count1][i - start1] = '\0';
            }
            count1++;
            start1 = i + 1;
        }
    }

    // 문자열을 이동을 시켜주고 마지막에 null 문자를 추가를 해준다.
    int count2 = 0, start2 = 0;
    for (int i = 0; i < strlen(str2); i++) {
        if (str2[i] == ' ' || str2[i + 1] == '\0') {
            if (str2[i + 1] == '\0') {
                strncpy(words2[count2], &str2[start2], i - start2 + 1);
                words2[count2][i - start2 + 1] = '\0';
            } else {
                strncpy(words2[count2], &str2[start2], i - start2);
                words2[count2][i - start2] = '\0';
            }
            count2++;
            start2 = i + 1;
        }
    }

    // str1의 M 번째 단어와 str2의 N 번째 단어를 연결하여 하나의 단어로 만들어 출력
    // 단, 두 단어의 연결은 사전 순서상 빠른 단어 뒤에 순서가 늦은 단어를 연결한다.
    if (strcmp(words1[M], words2[N]) < 0) {
        strcpy(finalWord, words1[M]);
        strcat(finalWord, words2[N]);
    } else {
        strcpy(finalWord, words2[N]);
        strcat(finalWord, words1[M]);
    }

    // 하나의 단어를 만들어 한 번의 출력문으로 출력
    printf("%s\n", finalWord);
    return 0;
}
