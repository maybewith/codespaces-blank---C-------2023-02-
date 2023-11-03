// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

// 한 학생의 정보는 다음과 같다. (struct student)
struct student{
    //  이름 : 공백을 포함하지 않고 길이가 최대 9인 문자열 (널 문자까지 10 바이트만 선언하기)
    char name[10];
    
    // 학번 : 공백을 포함하지 않고 길이가 10인 문자열이고, 첫 4자리는 입학년도를 의미
    char number[11];
    
    // 지난학기 평균학점 : A, B, F 중 한 개의 학점 (문자)
    char point;
};

int main() {
    // 5명 학생의 이름과 각 학생의 학번 및 지난 학기 평균 학점을 입력받는다
    struct student s[5];
    for(int i=0;i<5;i++)
        scanf("%s %s %c",s[i].name,s[i].number,&s[i].point);
        
    // 다음 찾고자 하는 학생의 이름을 입력하면
    char wanttofind[10];
    int wanttofindyear;
    scanf("%s",wanttofind);
    
    // 반복문을 통해서 이름을 찾는다.
    for(int i=0;i<5;i++){
        if(strcmp(wanttofind,s[i].name)==0){
            printf(" %s %c",s[i].number,s[i].point);
        }
    }
    
    return 0;
}