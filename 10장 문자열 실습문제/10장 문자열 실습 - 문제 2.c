#include <stdio.h>

int main() {
    // 정수를 한 자리씩 문자로 변환
    int num;
    char str[10] = {0};

    // 임의의 정수를 입력을 받는다
    scanf("%d", &num);
    int idx = 0;

    // 마지막 자릿수부터 차례로 문자 배열에 저장한 후 출력
    while (num) {
        str[idx++] = '0' + num % 10;
        num /= 10;
    }

    // 출력 시 문자열 출력 %s 를 사용한다. (%c 사용금지)
    printf("%s\n", str);
    return 0;
}
