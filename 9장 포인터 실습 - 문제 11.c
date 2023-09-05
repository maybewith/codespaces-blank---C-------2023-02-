#include <stdio.h>

void strcopy(char *a, char *b) {
    for (int i = 0; i < 6; ++i) {
        *(b+i) = *(a+i);
    }
}

int main() {
    char a[6], b[6];
    scanf("%s", a);
    
    strcopy(a, b);
    printf("%s\n", b);
    return 0;
}
