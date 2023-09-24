#include <stdio.h>

int main() {
    // 공백을 포함하지 않는 문자열 2개를 받는다
    char str1[101], str2[101];
    scanf("%s%s", str1, str2);

    // 이들 문자열의 길이를 구하자 
    int len1 = 0, len2 = 0;
    while (str1[len1]) len1++;
    while (str2[len2]) len2++;

    // 첫 번째 문자열의 길이를 출력
    printf("%d\n", len1);

    // 불일치하면 0을 출력하시오
    if (len1 != len2) {
        printf("0\n");
        return 0;
    }

    // 불일치하면 0을 출력하시오
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            printf("0\n");
            return 0;
        }
    }

    //  일치하면 1 
    printf("1\n");
    return 0;
}
