#include <stdio.h>

int input(int *p);
int *sel_next(int *p, int *end);
int number(int *p, int *q);

int main() {
    int x[100];
    int N;
    int *start, *end;
    
    N = input(x);
    start = x;
    end = x + N;
    
    while (start < end) {
        int *next = sel_next(start, end);
        printf("%d*", number(start, next));
        start = next + 1;
    }
    
    printf("\n");
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

int *sel_next(int *p, int *end) {
    int sum = 0;
    while (p < end) {
        sum += *p;
        if (sum > 10) {
            return p - 1;
        }
        p++;
    }
    return p - 1;
}

int number(int *p, int *q) {
    int num = 0;
    for (; p <= q; ++p) {
        num = num * 10 + *p;
    }
    return num;
}
