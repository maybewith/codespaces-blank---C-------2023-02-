#include <stdio.h>  
#include <string.h> 

int main() {
    // 변수 선언: 문장, 단어 배열, 추가 단어, 단어 개수 저장할 변수, 추가 단어 존재 여부 확인 변수
    char sentence[201], words[21][200], additionalWord[200];  
    int count = 0;   
    int found = 0;  

    // 문장 입력 받기
    gets(sentence);
    // 추가 단어 입력 받기
    gets(additionalWord);

    char *start = sentence;  // 시작 포인터
    char *end;               // 끝 포인터

    // 문장을 단어 단위로 분리하기
    while (1) {
        // 공백 넘기기
        while (*start == ' ' && *start != '\0') start++;
        if (*start == '\0') break;  // 문자열 끝 도달 시 반복 종료
        end = start;
        // 단어의 끝 찾기
        while (*end != ' ' && *end != '\0') end++;

        // 단어 분리하여 배열에 저장하기
        strncpy(words[count], start, end - start);
        words[count][end - start] = '\0';  // 널 문자 추가
        printf("%s\n", words[count]);  // 분리한 단어 바로 출력

        // 추가 단어가 문장 안에 존재하는지 확인
        if (strcmp(words[count], additionalWord) == 0) {
            found = 1;  // 추가 단어를 찾았다면 found를 1로 설정
        }

        count++;  // 단어 개수 증가
        if (*end == '\0') break;  // 문자열 끝 도달 시 반복 종료
        start = end + 1;  // 다음 단어의 시작으로 이동
    }

    // 단어가 문장에 없다면 배열에 추가하고 바로 출력
    if (!found) {
        strcpy(words[count], additionalWord);
        printf("%s\n", additionalWord);  // 추가 단어 바로 출력
        count++;  // 단어 개수 증가
    }

    // 단어들을 사전순으로 정렬하기
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

    // 정렬된 단어들을 하나의 문자열로 출력하기
    for (int i = 0; i < count; i++) {
        if (i != 0) printf(" ");  // 첫 단어가 아니면 공백 출력
        printf("%s", words[i]);
    }
    printf("\n");  // 줄 바꿈 출력

    return 0;  // 프로그램 종료
}
