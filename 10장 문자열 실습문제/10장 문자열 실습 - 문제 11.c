#include <stdio.h>
#include <string.h>

int main() {
    // 공백을 포함하지 않는 문자열 str1과 str2 두 개를 입력 받는다.
    char str1[81], str2[11];
    scanf("%s %s", str1, str2);
    
    // 첫 번째 문자열의 길이를 출력한다.
    printf("%ld ", strlen(str1));
    
    // str2가 str1에 포함되어 있는 문자열이면 1을,
    // 포함되어 있지 않는 경우라면 0을 출력하시오.
    if (strstr(str1, str2) != NULL) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
