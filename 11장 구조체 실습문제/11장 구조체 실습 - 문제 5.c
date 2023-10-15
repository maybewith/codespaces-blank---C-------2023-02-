#include <stdio.h>

typedef struct {
    char name[8];
    int kor, eng, math;
    float avg;
    char grade;
} Student;

int main() {
    int N;
    
    scanf("%d", &N);

    Student students[N], *p;

    for (p = students; p < students + N; p++) {
        scanf("%s %d %d %d", p->name, &p->kor, &p->eng, &p->math);
        p->avg = (p->kor + p->eng + p->math) / 3.0;

        if (p->avg >= 90) {
            p->grade = 'A';
        } else if (p->avg >= 80) {
            p->grade = 'B';
        } else if (p->avg >= 70) {
            p->grade = 'C';
        } else {
            p->grade = 'D';
        }
    }

    for (p = students; p < students + N; p++) {
        printf("%s %.1f %c\n", p->name, p->avg, p->grade);
    }

    return 0;
}
