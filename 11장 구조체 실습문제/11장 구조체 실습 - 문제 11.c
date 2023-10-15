#include <stdio.h>

// 학생 정보를 담기 위한 구조체 선언
struct student{
    char name[10]; // 이름의 최대 길이는 9 + null 문자
    int score;
};

// 학생들 중에서 기말고사 점수가 최하위인 학생을 찾는 함수
// 반환값은 최하위 점수 학생의 구조체 포인터
struct student* select_min(struct student* st) {
    struct student* min = &st[0];
    for (int i = 1; i < 5; i++) {
        if (st[i].score < min->score) {
            min = &st[i];
        }
    }
    return min;
}

int main() {
    // 학생 5명의 구조체를 만들어준다.
    struct student st[5];

    // 5명 학생의 이름과 기말고사 점수를 입력받음
    for (int i = 0; i < 5; i++) {
        scanf("%s %d", st[i].name, &st[i].score);
    }

    // 기말고사 점수가 최하위인 학생의 포인터를 얻음
    struct student* minStudent = select_min(st);

    // 기말고사 점수가 최하위인 학생의 이름과 점수를 출력
    printf("%s %d\n", minStudent->name, minStudent->score);
    
    return 0;
}
