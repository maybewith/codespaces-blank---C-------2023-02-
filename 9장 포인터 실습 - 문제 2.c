#include <stdio.h>

int main() {
    char str[21];
    char *p;
    scanf("%s", str);
    p = str;
    
    while (*p != '#') p++;
    p--;

    while (p >= str) {
        printf("%c", *p);
        p--;
    }
    printf("\n");
    return 0;
}
