#include <stdio.h>
#include <stdlib.h>

// 택시 정보를 담는 구조체 선언 및 TAXI로 typedef
typedef struct taxi_info {
    char start[11];      // 출발지 정보
    char target[11];     // 목적지 정보
    double distance;     // 이동 거리 (단위: km)
    int t_time;          // 정체 시간 (단위: 초)
    char late_night;     // 심야운행 여부 ('Y' or 'N')
    int tot;             // 총 요금
} TAXI;

int main() {
    int N, i;
    int base_fee, fee_per_100m, fee_per_30sec; // 기본 요금, 100m당 요금, 30초당 요금
    
    // 사용자로부터 택시 정보의 개수(N) 입력 받음
    scanf("%d", &N);
    TAXI taxis[N]; // 택시 정보를 담을 구조체 배열 선언
    
    // 사용자로부터 N개의 택시 정보를 입력 받는 반복문
    for (i = 0; i < N; i++) {
        // 택시 정보 입력
        scanf("%s %s %lf %d %c", taxis[i].start, taxis[i].target, &taxis[i].distance, &taxis[i].t_time, &taxis[i].late_night);
        
        // 심야운행인 경우와 아닌 경우로 요금 계산 기준을 나눔
        if (taxis[i].late_night == 'Y') {
            base_fee = 4800;
            fee_per_100m = 120;
            fee_per_30sec = 120;
        } else {
            base_fee = 3800;
            fee_per_100m = 100;
            fee_per_30sec = 100;
        }
        
        // 기본 요금 설정
        taxis[i].tot = base_fee;
        
        // 2km를 초과하는 거리에 대한 추가 요금 계산
        if (taxis[i].distance > 2) {
            taxis[i].tot += ((int)((taxis[i].distance - 2) * 1000 / 100)) * fee_per_100m;
        }
        
        // 정체 시간에 따른 추가 요금 계산
        taxis[i].tot += ((int)(taxis[i].t_time / 30)) * fee_per_30sec;
        
        // 결과 출력: 출발지, 목적지, 총 요금
        printf("%s %s %d\n", taxis[i].start, taxis[i].target, taxis[i].tot);
    }
    
    return 0;
}
