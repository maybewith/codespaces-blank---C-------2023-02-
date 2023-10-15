#include <stdio.h>

// 학생의 데이터를 저장하는 구조체를 사용하시오.
struct Student{
    int gender; // 성별은 남자가 1, 여자가 2 로 입력받는다.
    float weight;
    float height;
};

int main() {
    // 필요한 변수들을 선언을 한다.
    int n;
    struct Student students[10];
    int gradeCount[3] = {0, 0, 0};

    // 학급 학생의 수를 입력 받는다.
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        // 각 학생의 성별, 체중, 키를 입력 받는다.
        scanf("%d %f %f", &students[i].gender, &students[i].weight, &students[i].height);
        
        // 표에 따라 신체등급별 인원 수를 출력하는 프로그램을 작성하시오.
        int grade;
        // 남자 신체등급별 표
        if (students[i].gender == 1) { 
            if (students[i].height < 165) {
                grade = students[i].weight < 60 ? 1 : (students[i].weight < 70 ? 3 : 2);
            } else if (students[i].height < 175) {
                grade = students[i].weight < 60 ? 2 : (students[i].weight < 70 ? 1 : 3);
            } else {
                grade = students[i].weight < 60 ? 3 : (students[i].weight < 70 ? 2 : 1);
            }
        } else {
        // 여자 신체등급별 표
            if (students[i].height < 165) {
                grade = students[i].weight < 50 ? 1 : (students[i].weight < 60 ? 3 : 2);
            } else if (students[i].height < 175) {
                grade = students[i].weight < 50 ? 2 : (students[i].weight < 60 ? 1 : 3);
            } else {
                grade = students[i].weight < 50 ? 3 : (students[i].weight < 60 ? 2 : 1);
            }
        }
        gradeCount[grade-1]++;
    }
    
    // 표에 따라 신체등급별 인원 수를 출력한다.
    printf("%d ", gradeCount[0]);
    printf("%d ", gradeCount[1]);
    printf("%d\n", gradeCount[2]);

    return 0;
}
