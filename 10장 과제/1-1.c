#include <stdio.h>
#include <string.h>

int main() {
    // 입력 받을 문자열과 정수, 그리고 임시 변수들을 선언한다.
    char A[21];
    char result[100];
    int N;
    int tempNum;
    int currentIndex = 0;
    int tempIndex;

    // 문자열 A와 정수 N을 입력받는다.
    scanf("%s", A);
    scanf("%d", &N);

    // 각 문자를 확인하며 변환 규칙을 적용한다.
    for (int i = 0; i < strlen(A); i++) {
        if (A[i] >= 'A' && A[i] <= 'Z') {
            // 대문자 변환
            result[currentIndex] = A[i] + N;
        } else if (A[i] >= 'a' && A[i] <= 'z') {
            // 소문자 변환
            result[currentIndex] = A[i] - N; 
        } else if (A[i] >= '0' && A[i] <= '9') { // 숫자인 경우
            tempNum = A[i] - '0'; 
            if (A[i + 1] >= '0' && A[i + 1] <= '9') {
                // 두 자리 수로 변환
                tempNum = tempNum * 10 + A[i + 1] - '0'; 

                // 다음 문자도 처리했으므로 인덱스를 하나 증가
                i++; 
                for (tempIndex = 0; tempIndex < N; currentIndex++, tempIndex++) {
                    // 숫자에 해당하는 알파벳으로 변환
                    result[currentIndex] = 'A' + tempNum - 1; 
                }
                currentIndex--; // 마지막 인덱스 조정
            } else {
                for (tempIndex = 0; tempIndex < N; currentIndex++, tempIndex++) {
                    result[currentIndex] = 'A' + tempNum - 1;
                }
                currentIndex--;
            }
        } else {
            // 그 외의 문자는 공백으로 변환
            result[currentIndex] = ' '; 
        }
        currentIndex++; 
    }
    // 문자열의 끝을 표시한다.
    result[currentIndex] = '\0'; 

    // 변환된 문자열을 출력한다.
    printf("%s", result); 
    return 0; 
}
