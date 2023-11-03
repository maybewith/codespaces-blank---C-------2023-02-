// Online C compiler to run C program online
#include <stdio.h>

// 주차장 이용 구조체 만들기
struct parking_info{
    int number;
    int phonenumber;
    char what;
    char royal;
    int what_royal;
    int time_of_parking;
    double cost;
};

// input 함수를 만들자
// 함수 원형: void input(struct parking_info *p, int N)
void input(struct parking_info *p, int n){
    // 일단은 입력을 받는다.
    struct parking_info *a = p;
    for(int i=0;i<n;i++){
        // 입력을 받는다.
        scanf("%d %d %c",&a->number,&a->phonenumber,&a->what);
        
        // 만약 정기 구독자인 경우와 아닌 경우를 나누기
        if(a->what=='S'){
            // 정기 구독을 신청하는지를 확인한다.
            scanf(" %c %d %d",&a->royal,&a->what_royal,&a->time_of_parking);
        } else {
            // 시간만 받고 나머지는 없는 걸로 한다.
            scanf(" %d",&a->time_of_parking);
        }
        a++;
    }
}

// 출력하는 함수를 만들자
// 함수 원형: void display(struct parking_info *p, int N)
void display(struct parking_info *p, int n){
    // 반복문을 통해서 출력을 해보자
    for(int i=0;i<n;i++){
        printf("%d %d %c %.lf\n",p->number,p->phonenumber,p->what,p->cost);
        p++;
    }
}

// 계산하는 함수를 만들자.
// 함수 원형: void compute(struct parking_info *p)
void compute(struct parking_info *p) {
    if (p->what == 'S') {
        if (p->royal == 'N') {
            // 정기권 종류별로 계산을 해야하면 한다.
            switch (p->what_royal) {
                case 7:
                    p->cost = 30000;
                    break;
                case 30:
                    p->cost = 100000;
                    break;
                case 180:
                    p->cost = 500000;
                    break;
            }
        } else {
            // 정기권을 가지고 있기에 가격 없음
            p->cost = 0;
        }
        // 시간을 초과하면 다음과 같이 계산
        if (p->time_of_parking > 240) {
            p->cost += (p->time_of_parking - 240) / 10 * 200;
        }
    } else if (p->what == 'D') {
        // 1일권 사용자들은 시간이 다음과 같다.
        p->cost = 5000;
        if (p->time_of_parking > 240) {
            p->cost += (p->time_of_parking - 240) / 10 * 200;
        }
    }
}

int main() {
    // 필요한 변수를 선언하자
    int n;
    scanf("%d",&n);
    struct parking_info p[n];
    
    // 필요한 함수 호출들을 한다.
    input(p,n);
    struct parking_info *ptr;
    for (ptr = p; ptr < p + n; ptr++) {
        compute(ptr);
    }
    display(p,n);
    

    return 0;
}