#include <stdio.h>

struct Student{
    char name[10];
    int score;
};

int main() {
    int n = 5;
    struct Student students[n];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", students[i].name, &students[i].score);
        sum += students[i].score;
    }

    int avg = sum / n;

    for (int i = 0; i < n; i++) {
        if (students[i].score <= avg) {
            printf("%s\n", students[i].name);
        }
    }

    return 0;
}
