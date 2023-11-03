// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

// 사람의 구조체를 만들어준다
struct person{
    int pen;
    int face;
    char name[20];
    double final;
};
// swap() 함수
// 함수 원형: void swap(struct person *p, struct person *q)
void swap(struct person *p, struct person *q){
    // p와 q는 구조체 배열의 두 원소의 주소이며, 두 원소의 내용을 바꾸는 작업을 한다
    struct person tmp=*q;
    *q=*p;
    *p=tmp;
}

int main() {
    // 지원자 수 N과 합격자 수 M이 입력된다
    int n,m;
    scanf("%d %d",&n,&m);
    
    struct person s[100];
    
    // 다음은 N명 지원자의 이름, 필기시험 점수, 면접시험 접수가 순서대로 입력된다
    for(int i=0;i<n;i++){
        scanf("%s %d %d",s[i].name,&s[i].pen,&s[i].face);
        
        // 점수의 합을 구하자
        s[i].final=s[i].pen*0.8+s[i].face*0.2;
    }
    
    // 출력순서는 선발순서(총점이 높은 합격자부터 낮은 합격자 순) 이다. 
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(s[i].final<s[j].final){
                swap((s+i),(s+j));
            }
        }
    }
    
    // 결과를 출력을 한다
    for(int i=0;i<m;i++){
        printf("%s %.1f\n",s[i].name,s[i].final);
    }
    
    return 0;
}