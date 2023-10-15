#include <stdio.h>

// 학생의 구조체를 만든다.
struct Student{
    char name[20];
    int score1, score2, score3;
    float avg;
    char grade;
};

int main() {
    // 학생의 수를 입력을 받는다.
    int N;
    scanf("%d", &N);

    // 구조체로 학생들을 선언을 한다.
    struct Student students[N];

    // N명의 학생에 대해 이름과 세 번 본 시험의 성적을 읽어 들인다.
    for (int i = 0; i < N; i++){
        scanf("%s %d %d %d", students[i].name, &students[i].score1, &students[i].score2, &students[i].score3);
        students[i].avg = (students[i].score1 + students[i].score2 + students[i].score3) / 3.0;

        if (students[i].avg >= 90) {
            // 학점은 90점 이상이면 A
            students[i].grade = 'A';
        } else if (students[i].avg >= 80) {
            // 학점은 80점 이상이면 B
            students[i].grade = 'B';
        } else if (students[i].avg >= 70) {
            // 학점은 70점 이상이면 C
            students[i].grade = 'C';
        } else {
            // 학점은 70점 미만이면 F를 부여하시오.
            students[i].grade = 'F';
        }
    }
    // , 각 학생의 이름과 평균점수(소수점이하 첫째자리 까지), 학점을 출력한다.
    for (int i = 0; i < N; i++) {
        printf("%s %.1f %c\n", students[i].name, students[i].avg, students[i].grade);
    }

    return 0;
}
