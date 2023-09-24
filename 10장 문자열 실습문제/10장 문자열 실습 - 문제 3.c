#include <stdio.h>

int main() {
    char str[101];
    scanf("%s", str);

    int len = 0;
    while (str[len]) len++;

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            printf("%c", str[j]);
        }
        for (int k = 0; k < i; k++) {
            printf("%c", str[k]);
        }
        printf("\n");
    }
    return 0;
}
