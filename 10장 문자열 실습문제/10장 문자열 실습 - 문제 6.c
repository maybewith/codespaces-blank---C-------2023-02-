#include <stdio.h>

int main() {
    char str1[41], str2[21];
    int pos, order;

    // 반전 여부를 추가로 입력 받은 후
    scanf("%s %s %d %d", str1, str2, &pos, &order);

    int len1 = 0, len2 = 0;
    while (str1[len1]) len1++;
    while (str2[len2]) len2++;

    // 삽입 위치 0은 첫 번째 위치에 삽입하라는 의미이다.
    for (int i = len1 + len2 - 1; i >= pos + len2; i--) {
        str1[i] = str1[i - len2];
    }

    if (order == 0) { // 정순 삽입
        for (int i = 0; i < len2; i++) {
            str1[pos + i] = str2[i];
        }
    } else { // 역순 삽입
        for (int i = 0; i < len2; i++) {
            str1[pos + i] = str2[len2 - 1 - i];
        }
    }

    // str1 배열의 크기는 삽입된 이후의 크기를 고려하여야 한다.
    str1[len1 + len2] = '\0'; // 이 부분이 추가되었습니다.
    printf("%s\n", str1);
    
    return 0;
}
