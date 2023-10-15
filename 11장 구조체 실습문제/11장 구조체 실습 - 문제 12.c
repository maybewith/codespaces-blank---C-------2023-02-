#include <stdio.h>
#include <string.h>

// 학생 정보를 담기 위한 구조체 선언
struct Student{
    char name[10];
    int scores[3];
    float avg;
};

// 10명 학생의 이름과 3회 퀴즈 점수를 입력받아 저장하는 함수
void read_data(struct Student students[10]) {
    for(int i = 0; i < 10; i++) {
        scanf("%s %d %d %d", students[i].name, &students[i].scores[0], &students[i].scores[1], &students[i].scores[2]);
    }
}

// 각 학생의 3회 퀴즈 점수의 평균을 계산하는 함수
void cal_avg(struct Student students[10]) {
    for(int i = 0; i < 10; i++) {
        students[i].avg = (students[i].scores[0] + students[i].scores[1] + students[i].scores[2]) / 3.0;
    }
}

// 학생들의 평균 점수를 기준으로 내림차순 정렬하는 함수
void sort(struct Student students[10]) {
    for(int i = 0; i < 9; i++) {
        for(int j = i+1; j < 10; j++) {
            if(students[i].avg < students[j].avg) {
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// 최고점과 최저점 학생, 그리고 하위 30%의 학생들의 이름과 평균 점수를 출력하는 함수
void print_score(struct Student students[10]) {
    printf("%s %.2f\n", students[0].name, students[0].avg);
    printf("%s %.2f\n", students[9].name, students[9].avg);

    for(int i = 7; i < 10; i++) {
        printf("%s %.2f\n", students[i].name, students[i].avg);
    }
}

int main() {
    struct Student students[10];
    read_data(students); // 데이터 읽기
    cal_avg(students);   // 평균 계산
    sort(students);      // 정렬 수행
    print_score(students);// 결과 출력
    return 0;
}
