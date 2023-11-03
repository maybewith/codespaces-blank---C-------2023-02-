#include <stdio.h>
#include <string.h>

// 택시 정보를 저장하기 위한 구조체 선언
typedef struct taxi_info {
    char start[11];       // 출발지
    char target[11];      // 목적지
    double distance;      // 이동 거리 (km)
    int t_time;           // 정체 시간 (초)
    char late_night;      // 심야운행 여부 ('Y' or 'N')
    int tot;              // 총 택시 요금
} TAXI;

// 택시 요금이 가장 큰 구조체 원소의 주소를 반환하는 함수
TAXI* sel_max(TAXI *p, int N, char *s, char *d) {
    TAXI *max_taxi = NULL;  // 가장 큰 택시 요금을 가진 구조체 원소의 주소를 저장할 포인터

 
    // 모든 구조체 원소들을 검사
    for (TAXI *i = p; i < p+N; i++) {
        // 해당 원소의 출발지와 목적지가 입력받은 s와 d와 같은 경우
        if (strcmp((i)->start, s) == 0 && strcmp((i)->target, d) == 0) {
            // 아직 최대 요금 원소를 찾지 못했거나 현재 원소의 요금이 지금까지의 최대 요금보다 큰 경우
            if (!max_taxi || max_taxi->tot < (i)->tot) {
                max_taxi = (i);  // 최대 요금 원소 업데이트
            }
        }
    } 

    return max_taxi;  // 최대 요금 원소의 주소 반환
}

int main() {
    int N;  // 택시 정보의 개수
    scanf("%d", &N);

    TAXI taxis[N];  // 택시 정보를 저장할 구조체 배열 선언

    // N개의 택시 정보 입력
    for (int i = 0; i < N; i++) {
        scanf("%s %s %lf %d %c", taxis[i].start, taxis[i].target, &taxis[i].distance, &taxis[i].t_time, &taxis[i].late_night);

        // 심야 운행 여부에 따른 요금 결정
        int basic_rate = (taxis[i].late_night == 'Y') ? 4800 : 3800;
        int distance_rate = (taxis[i].late_night == 'Y') ? 120 : 100;
        int time_rate = (taxis[i].late_night == 'Y') ? 120 : 100;

        taxis[i].tot = basic_rate;  // 기본 요금 할당

        // 추가 거리 요금 계산
        if (taxis[i].distance > 2) {
            taxis[i].tot += ((int)((taxis[i].distance - 2) * 10)) * distance_rate;
        }

        // 정체 시간에 따른 추가 요금 계산
        taxis[i].tot += (taxis[i].t_time / 30) * time_rate;
    }

    char s[11], d[11];  // 검색할 출발지와 목적지
    scanf("%s %s", s, d);

    // 가장 큰 택시 요금을 가진 구조체 원소 찾기
    TAXI *max_taxi = sel_max(taxis, N, s, d);
    if (max_taxi) {
        printf("%.2lf %d %c %d\n", max_taxi->distance, max_taxi->t_time, max_taxi->late_night, max_taxi->tot);
    } else {
        printf("No such route found!\n");  // 해당 경로의 택시 정보가 없는 경우 출력
    }

    return 0;
}
