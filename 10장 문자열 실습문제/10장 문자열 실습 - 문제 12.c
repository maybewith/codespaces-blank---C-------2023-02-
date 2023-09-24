#include <stdio.h>

int main() {
    // 공백을 포함하는 문자열 str1과 공백을 포함하지 않는 문자열 str2를
    // 입력 받는다.
    char str1[101], str2[101];
    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);

    // 문자열 길이 계산 (strlen 함수처럼 동작)
    int len1 = 0, len2 = 0;
    while (str1[len1] && str1[len1] != '\n') len1++;
    while (str2[len2] && str2[len2] != '\n') len2++;

    // 줄바꿈 문자 제거
    if (str1[len1] == '\n') str1[len1] = '\0';
    if (str2[len2] == '\n') str2[len2] = '\0';

    // str2가 str1에 몇 번 나타나는지, 그 횟수 세어서 변수에 저장 
    int count = 0;
    for (int i = 0; i <= len1 - len2;) {
        int j;
        for (j = 0; j < len2; j++) {
            if (str1[i + j] != str2[j]) {
                break;
            }
        }
        
        // 만약 같다면 다음과 같이 한다.
        if (j == len2) {
            count++;
            i += len2;
        } else {
            i++;
        }
    }
    
    // 결과를 출력을 한다.
    printf("%d\n", count);
    return 0;
}
