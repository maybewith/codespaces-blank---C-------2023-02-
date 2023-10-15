#include <stdio.h>
#include <string.h>

// 주어진 문자열에서 "영어 알파벳과 공백을 제외한 문자"의 개수를 반환하는 함수
int check_u(char *p, char *q) {
    int count = 0;
    // 포인터 p가 q까지 문자들을 확인하면서 반복문 실행
    while (p <= q) {
        // 현재 문자가 영어 알파벳과 공백이 아니면 count 증가
        if (!((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z') || (*p == ' '))) {
            count++;
        }
        // 다음 문자를 가리키도록 포인터 p 이동
        p++;  
    }
    return count;
}

int main() {
    // 필요한 변수를 선언하고 입력을 받는다.
    int N;  
    scanf("%d", &N);

    // 줄바꿈 문자 제거
    getchar();  

    // 최대 특수문자 개수를 가진 문자열 저장
    char maxString[101];  
    // 최대 특수문자 개수 초기화
    int maxCount = -1;  

    // N개의 문자열을 입력받으면서 처리
    for (int i = 0; i < N; i++) {
        // 입력받은 문자열 저장
        char inputString[101];  
        fgets(inputString, 101, stdin);
        
        // 마지막에 줄바꿈 문자가 있다면 제거
        if (inputString[strlen(inputString) - 1] == '\n') {
            inputString[strlen(inputString) - 1] = '\0';  // 줄바꿈 문자 제거
        }

        // 현재 문자열의 "영어 알파벳과 공백을 제외한 문자"의 개수 계산
        int currentCount = check_u(inputString, inputString + strlen(inputString) - 1);
        
        // 현재 문자열의 특수문자 개수가 이전 최대값보다 크면 갱신
        if (currentCount > maxCount) {
            maxCount = currentCount;
            strcpy(maxString, inputString);  // 최대 특수문자 개수를 가진 문자열 갱신
        }
    }

    // 결과 출력
    printf("%s\n", maxString);

    return 0;
}
