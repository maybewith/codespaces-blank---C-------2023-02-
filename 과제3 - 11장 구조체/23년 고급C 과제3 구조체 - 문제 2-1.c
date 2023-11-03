// Online C compiler to run C program online
#include <stdio.h>
// 학생의 구조체를 선언한다.
struct student{
    // 학생의 이름 저장 변수
    char name[21];
    
    // 성적을 저장할 변수
    int kor,eng,math;
};

// 평균의 구조체를 만들어 준다.
struct average{
    // 평균점수를 저정할 변수 3개를 선언한다.
    double kor;
    double eng;
    double math;
};

struct average calculate_avg(struct student *st, int n){
    // 돌려줄 평균 구조체를 선언하고 합을 모두 시킨다.
    struct average tmp;

    // 초기화 시키기
    tmp.kor=0; tmp.eng=0; tmp.math=0;
    
    // 학생들의 점수를 모두 더한다.
    struct student *p;
    for(p=st;p<st+n;p++){
        tmp.kor+=p->kor;
        tmp.eng+=p->eng;
        tmp.math+=p->math;
    }
    
    // 있는 학생의 수 만큼 나눠준다.
    tmp.kor=tmp.kor/n;
    tmp.eng=tmp.eng/n;
    tmp.math=tmp.math/n;
    
    return tmp;
}

int main() {
    // 입력을 받을 개수를 입력을 받는다.
    int n;
    scanf("%d",&n);
    
    // 학생들의 성적을 입력을 받는다.
    struct student student_scores[n];
    for(int i=0;i<n;i++){
        scanf("%s %d %d %d",student_scores[i].name,&student_scores[i].kor,&student_scores[i].eng,&student_scores[i].math);
    }
    // calculate_average 함수를 통해서 값을 구한다.
    struct average result = calculate_avg(student_scores,n);
    
    // 결과를 출력을 한다.
    printf("%.1lf %.1lf %.1lf\n",result.kor,result.eng,result.math);
    
    // 각 미달인 학생을 출력을 한다.
    int kor,eng,math;
    kor=0;eng=0;math=0;
    for(int i=0;i<n;i++){
        if(student_scores[i].kor<result.kor){
            kor++;
        }
        if(student_scores[i].eng<result.eng){
            eng++;
        }
        if(student_scores[i].math<result.math){
            math++;
        }
    }
    
    // 결과를 출력하기
    printf("%d %d %d",kor,eng,math);
    
    return 0;
}