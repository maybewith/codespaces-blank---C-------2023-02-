#include <stdio.h>

// 주차 정보 구조체 정의
struct parking_info{
    int vehicle_num;         // 차량 번호
    int customer_phone;     // 고객 전화번호
    char product;           // 상품 (S 혹은 D)
    char subscription;      // 정기권 가입 유무 (Y 혹은 N)
    int subscription_type;  // 종류 (7, 30, 180)
    int parking_time;       // 주차시간 (분)
    double fee;             // 요금
};

void input(struct parking_info *p, int N);           // 입력 함수 선언
void compute(struct parking_info *p);                // 요금 계산 함수 선언
void display(struct parking_info *p, int N);         // 출력 함수 선언
void parking_info_sort(struct parking_info *p, int N); // 정렬 함수 선언

int main() {
    int N;
    scanf("%d", &N);  // 차량 수 입력

    struct parking_info park[N]; // 주차 정보 배열 생성
    input(park, N);      // 주차 정보 입력

    struct parking_info *p_ptr;
    // 모든 차량에 대한 요금 계산
    for (p_ptr = park; p_ptr < park + N; p_ptr++) {
        compute(p_ptr);
    }

    parking_info_sort(park, N); // 주차 정보 정렬
    display(park, N);          // 요금 출력
    return 0;
}

void input(struct parking_info *p, int N) {
    struct parking_info *p_ptr;
    for (p_ptr = p; p_ptr < p + N; p_ptr++) {
        // 기본 정보 입력 (차량 번호, 전화번호, 상품)
        scanf("%d %d %c", &p_ptr->vehicle_num, &p_ptr->customer_phone, &p_ptr->product);
        
        if (p_ptr->product == 'S') {
            // 정기권의 경우 추가 정보 입력
            scanf(" %c %d", &p_ptr->subscription, &p_ptr->subscription_type);
        }
        
        // 주차 시간 입력
        scanf("%d", &p_ptr->parking_time);
    }
}

void compute(struct parking_info *p) {
    int extra_time_fee = 0;
    // 추가 시간 요금 계산
    if (p->parking_time > 240) {
        extra_time_fee = (p->parking_time - 240) / 10 * 200;
    }

    // 상품별 요금 계산
    if (p->product == 'D') {
        p->fee = 5000 + extra_time_fee;
    } else if (p->product == 'S') {
        if (p->subscription == 'N') {
            // 정기권 가입이 아닌 경우
            switch (p->subscription_type) {
                case 7:
                    p->fee = 30000 + extra_time_fee;
                    break;
                case 30:
                    p->fee = 100000 + extra_time_fee;
                    break;
                case 180:
                    p->fee = 500000 + extra_time_fee;
                    break;
            }
        } else {
            // 정기권 가입자의 경우 4시간을 초과하지 않으면 비용 없음
            if (p->parking_time > 240) {
                p->fee = extra_time_fee;
            } else {
                p->fee = 0;
            }
        }
    }
}

void parking_info_sort(struct parking_info *p, int N) {
    struct parking_info *i_ptr, *j_ptr;
    // 버블 정렬을 사용하여 주차 정보 정렬
    for (i_ptr = p; i_ptr < p + N - 1; i_ptr++) {
        for (j_ptr = p; j_ptr < p + N - (i_ptr - p) - 1; j_ptr++) {
            // 상품을 기준으로 오름차순 정렬, 동일 상품일 경우 차량 번호로 정렬
            if (j_ptr->product > (j_ptr + 1)->product || 
               (j_ptr->product == (j_ptr + 1)->product && j_ptr->vehicle_num > (j_ptr + 1)->vehicle_num)) {
                struct parking_info temp = *j_ptr;
                *j_ptr = *(j_ptr + 1);
                *(j_ptr + 1) = temp;
            }
        }
    }
}

void display(struct parking_info *p, int N) {
    struct parking_info *p_ptr;
    double totalS = 0, totalD = 0;
    // 모든 차량의 정보와 요금 출력
    for (p_ptr = p; p_ptr < p + N; p_ptr++) {
        printf("%d %d %c %.0f\n", p_ptr->vehicle_num, p_ptr->customer_phone, p_ptr->product, p_ptr->fee);
        // 상품별 총 요금 계산
        if (p_ptr->product == 'S') totalS += p_ptr->fee;
        else totalD += p_ptr->fee;
    }
    // 총 요금 출력
    printf("%.0f %.0f %.0f\n", totalD, totalS, totalD + totalS);
}
