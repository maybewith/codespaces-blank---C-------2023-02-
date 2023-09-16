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
    
    while (start < end-1) {
        int *next = sel_next(start, end);
        printf("%d\n", number(start, next));
        start = next;
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
    int *initial = p;
    int increasing = 1;
    
    if (p >= end - 1) {
        return end - 1;
    }

    if (*p > *(p + 1)) {
        increasing = 0;
    }
    p++;

    while (p < end - 1) {
        if (increasing && *p > *(p + 1)) {
            return p;
        } else if (!increasing && *p < *(p + 1)) {
            return p;
        }
        p++;
    }
    return end - 1;
}

int number(int *p, int *q) {
    int num = 0;
    while (p <= q) {
        num = num * 10 + *p;
        p++;
    }
    return num;
}
