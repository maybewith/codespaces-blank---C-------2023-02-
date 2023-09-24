#include <stdio.h>
#include <string.h>

// 인자: 문자열의 시작주소를 나타내는 포인터 변수
int check(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        // 회문 여부를 판단한다.(대문자, 소문자 구별함)
        if (str[i] != str[len - i - 1]) {
            // 회문이 아닐 경우에는 0
            return 0;
        }
    }
    // 회문일 경우에는 1
    return 1;
}

int main() {
    // 공백을 포함하지 않는 문자열 하나를 입력 받는다.
    char str[31];
    scanf("%s", str);
    
    // 입력 받은 문자열의 회문 여부를 판단한다.
    printf("%ld %d\n", strlen(str), check(str));

    return 0;
}
