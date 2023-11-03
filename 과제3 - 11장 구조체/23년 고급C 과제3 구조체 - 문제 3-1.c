#include <stdio.h>
#include <string.h>

// 호텔 정보를 저장할 구조체 정의
struct hotel_info {
    char name[31];       // 호텔 이름
    int grade;           // 호텔 등급
    double reputation;   // 호텔 평판도
    double distance;     // 도시 중심으로부터의 거리
    char breakfast[2];   // 조식 포함 여부
};

// 호텔 정보를 입력받는 함수
int in_hotel_info(struct hotel_info *p) {
    int count = 0;  // 입력된 호텔의 수를 저장할 변수
    struct hotel_info *current = p;

    // 무한 반복문을 사용하여 호텔 정보 입력받기
    while (1) {
        // 호텔 이름 입력 받기
        scanf("%s", current->name);
        
        // 호텔 이름이 "0"이면 입력 종료
        if (strcmp(current->name, "0") == 0) {
            break;
        }

        // 호텔의 등급, 평판도, 거리, 조식 포함 여부 입력 받기
        scanf("%d %lf %lf %s", &current->grade, &current->reputation, &current->distance, current->breakfast);
        
        // 호텔의 수 증가
        count++;
        current++;
    }

    // 입력된 호텔의 수 반환
    return count;
}

// 조건에 맞는 최고 평판도의 호텔 정보를 출력하는 함수
void out_hotel_info(struct hotel_info *p, int N, int G, double D) {
    struct hotel_info *best_hotel = NULL;  // 최고 평판도의 호텔 정보를 저장할 포인터
    struct hotel_info *current = p;

    // 모든 호텔 정보를 순회하면서 조건에 맞는 호텔을 찾기
    for (int i = 0; i < N; i++, current++) {
        // 현재 호텔이 조건에 부합하면
        if (current->grade >= G && current->distance <= D) {
            // 아직 best_hotel이 지정되지 않았거나, 현재 호텔의 평판도가 더 높거나, 
            // 평판도가 같고 호텔 이름이 사전 순으로 더 앞서는 경우
            if (best_hotel == NULL || current->reputation > best_hotel->reputation ||
                (current->reputation == best_hotel->reputation && strcmp(current->name, best_hotel->name) < 0)) {
                best_hotel = current;  // 현재 호텔을 최고 평판도의 호텔로 지정
            }
        }
    }

    // 조건에 부합하는 최고 평판도의 호텔 정보를 출력
    if (best_hotel != NULL) {
        printf("%s %d %.1lf %.1lf %s\n", best_hotel->name, best_hotel->grade, best_hotel->reputation,
               best_hotel->distance, best_hotel->breakfast);
    }
}

int main() {
    struct hotel_info hotels[100];  // 호텔 정보를 저장할 배열 선언

    // 호텔 정보 입력받기
    int N = in_hotel_info(hotels);

    int G;       // 원하는 호텔 등급
    double D;    // 원하는 거리

    // 원하는 호텔 등급과 거리 입력받기
    scanf("%d %lf", &G, &D);

    // 조건에 맞는 호텔 정보 출력
    out_hotel_info(hotels, N, G, D);

    return 0;
}
