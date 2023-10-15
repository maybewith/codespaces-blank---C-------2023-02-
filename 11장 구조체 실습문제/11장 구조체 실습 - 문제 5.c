#include <stdio.h>

// 학생의 구조체를 만든다.
struct Student{
    char name[8];
    int kor, eng, math;
    float avg;
    char grade;
};

int main() {
    // 입력을 받을 학생의 수를 입력을 받는다.
    int N;
    scanf("%d", &N);

    // 입력을 받을 학생을 선언하고, 포인터를 선언한다.
    struct Student students[N], *p;

    // 반드시 구조체 배열과, 구조체 포인터 사용. 반복문으로 배열 훑어볼 시, 주소를 이용하여 반복문 구현 (강의자료 7주차 1강 p. 10)
    for (p = students; p < students + N; p++) {
        // 학생에 대한 정보(이름, 국어 성적, 영어 성적, 수학 성적)를
        // 입력 받는다.
        scanf("%s %d %d %d", p->name, &p->kor, &p->eng, &p->math);
        
        // 평균 성적을 계산하여 저장을 한다.
        p->avg = (p->kor + p->eng + p->math) / 3.0;

        if (p->avg >= 90) {
            // 90 이상 100 이하: A
            p->grade = 'A';
        } else if (p->avg >= 80) {
            // 80 이상 90 미만: B
            p->grade = 'B';
        } else if (p->avg >= 70) {
            // 70 이상 80 미만: C
            p->grade = 'C';
        } else {
            // 70 미만: D
            p->grade = 'D';
        }
    }

    // 학생의 이름과 평균 성적(소수점 이하 첫째자리까지)과 학점을 출력
    for (p = students; p < students + N; p++) {
        printf("%s %.1f %c\n", p->name, p->avg, p->grade);
    }

    return 0;
}
