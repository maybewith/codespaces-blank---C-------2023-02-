#include <stdio.h>

int main() {
    // 공백을 포함하지 않는 문자열을 입력
    char str[21];
    scanf("%s", str);

    // 소문자만 출력하게 만드는 반복문
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}
