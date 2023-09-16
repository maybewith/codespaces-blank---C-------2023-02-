#include <stdio.h>

int input(int *p);
int *sel_next(int *p, int N, int M);
int number(int *p, int *q);

int main() {
    int x[100];
    int N, M;
    int *end;
    
    N = input(x);
    scanf("%d", &M);
    
    end = sel_next(x, N, M);
    printf("%d\n", number(x + M, end));
    
    return 0;
}

int input(int *p) {
    int count = 0;
    while (1) {
        scanf("%d", p + count);
        if (*(p + count) == -1) break;
        count++;
    }
    return count;
}

int *sel_next(int *p, int N, int M) {
    int *end = p + M;
    
    for (; end < p + N - 1; ++end) {
        if (*(end + 1) <= *end) {
            return end;
        }
    }
    return end;
}

int number(int *p, int *q) {
    int num = 0;
    for (; p <= q; ++p) {
        num = num * 10 + *p;
    }
    return num;
}
