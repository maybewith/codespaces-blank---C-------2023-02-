#include <stdio.h>
#include <string.h>

int main() {
    // 두 개의 공백을 포함하지 않는 문자열을 scanf( ) 함수로 읽는다.
    char str1[51], str2[51];
    scanf("%s %s", str1, str2);
    
    // 입력 문자열은 소문자로만 구성된다.(사전 역순)
    if (strcmp(str1, str2) < 0) {
        // 문자열 처리 표준 함수를 사용해도 됨.
        printf("%s%s\n", str2, str1);
    } else {
        // 문자열 처리 표준 함수를 사용해도 됨.
        printf("%s%s\n", str1, str2);
    }

    return 0;
}
