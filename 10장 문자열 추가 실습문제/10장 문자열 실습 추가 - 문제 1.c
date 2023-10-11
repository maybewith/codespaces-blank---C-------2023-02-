#include <stdio.h>
#include <string.h>

int main() {
    // 문자열은 알파벳 소문자로만 구성된다고 가정하며, 문자열의 길이는 최대 100이다.
    char input[101];
    
    // 문자열 입력 시 gets 사용하고, 문자열의 길이는 최대 100이다.
    gets(input);

    // 필요한 변수들을 선언을 한다.
    char *ptr = input;
    char *start = ptr;
    char minWord[101] = "";
    char currentWord[101];
    int isFirst = 1;  
    
    while (*ptr) {
        // 단어와 단어 사이에는 공백 문자가 하나만 존재한다.
        if (*ptr == ' ' || *(ptr + 1) == '\0') {  
            if (*(ptr + 1) == '\0') {  
                strncpy(currentWord, start, ptr - start + 1);
                currentWord[ptr - start + 1] = '\0';
            } else {
                strncpy(currentWord, start, ptr - start);
                currentWord[ptr - start] = '\0';
            }
            
            // 입력된 문자열에 나타난 단어 중, 사전적 순서가 가장 빠른 단어를 선택
            if (isFirst || strcmp(minWord, currentWord) > 0) {
                strcpy(minWord, currentWord);
                isFirst = 0;
            }
            
            // 인덱스를 조정을 해준다.
            start = ptr + 1;  
        }
        ptr++;
    }

    // 문자열을 화면으로 출력할 때 %c 사용금지한다.
    printf("%s\n", minWord);
    return 0;
}
