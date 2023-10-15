#include <stdio.h>

// 학생의 구조체를 만들어준다.
struct Student{
    char name[10];
    int score;
};

int main() {
    // 필요한 변수들을 선언을 해준다.
    int n = 5;
    struct Student students[n];
    int sum = 0;

    // 5명 학생의 이름과 기말고사 점수를 입력 받는다.
    for (int i = 0; i < n; i++) {
        scanf("%s %d", students[i].name, &students[i].score);
        sum += students[i].score;
    }

    // 전체 평균을 계산하여 저장한다.
    int avg = sum / n;

    // 평균 이하의 점수를 받은 학생의 이름을 출력한다.
    for (int i = 0; i < n; i++) {
        if (students[i].score <= avg) {
            printf("%s\n", students[i].name);
        }
    }

    return 0;
}
