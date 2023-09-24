#include <stdio.h>
#include <string.h>

int main() {
    // 사용자로부터 N 줄의 공백을 포함하는 문자열을 읽는다.
    int n;
    scanf("%d", &n);
    getchar(); // 줄바꿈 문자를 제거합니다.
    
    char minStr[101];
    int minLen = 101;
    
    // 사용자로부터 N 줄의 공백을 포함하는 문자열 입력을 받는다.
    for (int i = 0; i < n; i++) {
        char str[101];
        fgets(str, sizeof(str), stdin);
        
        int len = strlen(str);
        if (str[len - 1] == '\n') {
            str[len - 1] = '\0'; // 줄바꿈 문자를 제거합니다.
            len--;
        }

        // 입력 문자열이 비어 있지 않은 경우만 최소 길이를 확인하고 업데이트합니다.
        if (len > 0 && len < minLen) {
            minLen = len;
            strcpy(minStr, str);
        }
    }
    
    // 가장 길이가 작은 공백을 포함하는 문자열을 출력을 한다.
    // 출력 시 문자열 출력을 사용한다. (%c 사용금지)
    printf("%s\n", minStr);
    return 0;
}
