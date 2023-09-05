#include <stdio.h>

int main() {
    char ch[10];
    char *p, *q;
    int max_count = 0;
    char max_char = 0;

    // 10개의 문자 입력
    for (p = ch; p < ch + 10; p++) {
        scanf(" %c", p);  // 공백을 무시하고 문자를 읽어옵니다.
    }

    // 빈도수 체크
    for (p = ch; p < ch + 10; p++) {
        int count = 0;
        for (q = ch; q < ch + 10; q++) {
            if (*p == *q) {
                count++;
            }
        }

        // 빈도수가 현재 최대 빈도수보다 높은 경우
        if (count > max_count) {
            max_count = count;
            max_char = *p;
        }
    }

    // 결과 출력
    printf("%c %d\n", max_char, max_count);

    return 0;
}
