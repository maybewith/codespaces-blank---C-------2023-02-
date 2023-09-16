#include <stdio.h>

// Input function
void input(int *p, int M) {
    int *ptr = p;
    for (int i = 0; i < M; ++i, ++ptr) {
        scanf("%d", ptr);
    }
}

// Function to find the most frequent element
int* sel_max(int *p, int M) {
    int count, maxCount = 0;
    int *maxPtr = p;
    int *ptr1, *ptr2;
    
    for (ptr1 = p; ptr1 < p + M; ++ptr1) {
        count = 0;
        for (ptr2 = p; ptr2 < p + M; ++ptr2) {
            if (*ptr1 == *ptr2) {
                ++count;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxPtr = ptr1;
        }
    }
    return maxPtr;
}

// Output function
void output(int *p, int N) {
    int *ptr = p;
    for (int i = 0; i < N; ++i, ++ptr) {
        printf("%d ", *ptr);
    }
    printf("\n");
}

// Main function
int main(void) {
    int in[100], out[100], *max, i, N, M;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; ++i) {
        input(in, M);
        max = sel_max(in, M);
        out[i] = *max;
    }
    output(out, N);
    return 0;
}
