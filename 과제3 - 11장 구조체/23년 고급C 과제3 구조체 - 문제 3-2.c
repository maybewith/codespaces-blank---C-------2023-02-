#include <stdio.h>
#include <string.h>

// 호텔 정보를 표현하기 위한 구조체 정의
struct hotel_info {
    char name[31];          // 호텔 이름
    int grade;              // 호텔 등급
    double reputation;     // 호텔 평판도
    double distance;       // 도시 중심부로부터의 거리
    char breakfast[2];     // 조식 포함 여부 ('Y' 또는 'N')
};

// 호텔 정보를 입력받아 배열에 저장하고 입력된 호텔의 수를 반환하는 함수
int in_hotel_info(struct hotel_info *p) {
    int count = 0;                                  // 입력된 호텔의 수를 저장하기 위한 변수
    struct hotel_info *current = p;                 // 현재 호텔 정보를 가리키는 포인터
    while (1) {
        scanf("%s", current->name);
        // "0"이 입력되면 호텔 정보 입력 종료
        if (strcmp(current->name, "0") == 0) {
            break;
        }
        scanf("%d %lf %lf %s", &current->grade, &current->reputation, &current->distance, current->breakfast);
        count++;
        current++;
    }
    return count;
}

// 조건을 만족하는 호텔 정보를 출력하는 함수
void out_hotel_info(struct hotel_info *p, int N, int G, double D) {
    struct hotel_info sorted_hotels[100]; // 조건에 맞는 호텔들을 저장하기 위한 배열
    int count = 0;                         // 조건에 맞는 호텔의 수를 저장하기 위한 변수
    struct hotel_info *ptr;                // 호텔 정보를 가리키는 포인터

    // 조건(G 이상의 등급, D 이하의 거리)에 맞는 호텔을 sorted_hotels 배열에 저장
    for (ptr = p; ptr < p + N; ptr++) {
        if (ptr->grade >= G && ptr->distance <= D) {
            *(sorted_hotels + count) = *ptr;
            count++;
        }
    }

    // 버블 정렬을 사용하여 평판도가 높은 순서대로 호텔을 정렬
    // 평판도가 같은 경우, 이름 순서대로 정렬
    for (int i = 0; i < count - 1; i++) {
        struct hotel_info *j_ptr;
        for (j_ptr = sorted_hotels; j_ptr < sorted_hotels + count - 1 - i; j_ptr++) {
            if (j_ptr->reputation < (j_ptr + 1)->reputation || 
                (j_ptr->reputation == (j_ptr + 1)->reputation && strcmp(j_ptr->name, (j_ptr + 1)->name) > 0)) {
                struct hotel_info temp = *j_ptr;
                *j_ptr = *(j_ptr + 1);
                *(j_ptr + 1) = temp;
            }
        }
    }

    // 조건에 맞는 호텔의 정보를 출력
    for (ptr = sorted_hotels; ptr < sorted_hotels + count; ptr++) {
        printf("%s %d %.1lf %.1lf %s\n", ptr->name, ptr->grade, ptr->reputation, ptr->distance, ptr->breakfast);
    }
}

// 메인 함수
int main() {
    struct hotel_info hotels[100];          // 호텔 정보를 저장하기 위한 배열
    int N = in_hotel_info(hotels);          // 호텔 정보 입력
    int G;                                  // 사용자가 원하는 호텔의 최소 등급
    double D;                               // 사용자가 원하는 호텔의 최대 거리

    scanf("%d %lf", &G, &D);                // 원하는 호텔의 등급과 거리 입력
    out_hotel_info(hotels, N, G, D);        // 조건에 맞는 호텔의 정보 출력

    return 0;
}
