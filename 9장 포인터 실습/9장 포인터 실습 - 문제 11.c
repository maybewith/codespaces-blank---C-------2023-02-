#include <stdio.h>

// 문자열을 복사를 해주는 함수
void strcopy(char *a, char *b) {
    // 반복문을 통해서 문자열을 복사한다
    for (int i = 0; i < 6; ++i) {
        *(b+i) = *(a+i);
    }
}

int main() {
    // 사용할 변수를 선언을 해준다
    char a[6], b[6];

    // 문자열을 입력을 받는다
    scanf("%s", a);
    
    // 함수를 통해서 문자열을 복사를 시킨다
    strcopy(a, b);

    // 결과를 출력을 해준다
    printf("%s\n", b);

    return 0;
}
