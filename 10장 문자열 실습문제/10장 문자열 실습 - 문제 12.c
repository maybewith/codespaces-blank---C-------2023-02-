#include <stdio.h>
#include <string.h>

int main() {
    char str1[101], str2[101];
    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);

    // 줄바꿈 문자 제거
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    int count = 0;
    for (int i = 0; i <= len1 - len2;) {
        if (strncmp(str1 + i, str2, len2) == 0) {
            count++;
            i += len2;
        } else {
            i++;
        }
    }
    
    printf("%d\n", count);
    return 0;
}
