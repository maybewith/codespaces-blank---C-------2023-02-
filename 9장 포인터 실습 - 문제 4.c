#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int ar[3];
    int *p;
    
    for (p = ar; p < ar + 3; p++) {
        scanf("%d", p);
    }

    qsort(ar, 3, sizeof(int), compare);

    p = ar + 1;
    printf("%d\n", *p);

    return 0;
}
