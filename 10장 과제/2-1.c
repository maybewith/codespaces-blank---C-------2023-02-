#include <stdio.h>  
#include <string.h> 

int main() {
    // 변수 선언: 문장과 단어를 저장할 배열, 단어 개수 저장할 변수
    char sentence[201], words[20][200];  
    int count = 0; 

    // 문장 입력 받기
    gets(sentence);

    char *start = sentence;  // 시작 포인터
    char *end;               // 끝 포인터

    // 단어 분리하기
    while (1) {
        // 공백 넘기기
        while (*start == ' ' && *start != '\0') start++;
        // 문자열 끝 도달 시 반복 종료
        if (*start == '\0') break;  
        end = start;
        // 단어의 끝 찾기
        while (*end != ' ' && *end != '\0') end++;
        
        // 단어 분리하여 저장하기
        strncpy(words[count], start, end - start);
        // 널 문자 추가
        words[count][end - start] = '\0';  
        // 분리한 단어 바로 출력
        printf("%s\n", words[count]);  
        // 단어 개수 증가
        count++;  

        if (*end == '\0') break;  // 문자열 끝 도달 시 반복 종료
        start = end + 1;  // 다음 단어의 시작으로 이동
    }

    // 단어를 사전순으로 정렬하기
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            // strcmp를 사용하여 단어 순서 확인 및 교환
            if (strcmp(words[i], words[j]) > 0) {
                char temp[200];
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    // 정렬된 단어 출력하기
    for (int i = 0; i < count; i++) {
        // 첫 단어가 아니면 공백 출력
        if (i != 0) printf(" ");  
        printf("%s", words[i]);
    }
    printf("\n");  

    return 0;  
}
