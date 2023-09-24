#include <stdio.h>

int main() {
    // 공백을 포함하지 않는 문자열을 하나 입력을 받는다
    char str[101];
    scanf("%s", str);

    // 문자열의 길이 계산
    int len = 0;
    while (str[len]) len++;

    char temp[101];
    for (int i = 0; i < len; i++) {
        // 앞 부분은 그대로 복사
        for (int j = 0; j < len - i; j++) {
            temp[j] = str[i + j];
        }
        // 뒷 부분을 복사
        for (int j = 0; j < i; j++) {
            temp[len - i + j] = str[j];
        }
        // Null 문자를 끝에 추가
        temp[len] = '\0';
        printf("%s\n", temp);
    }
    return 0;
}
