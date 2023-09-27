#include <stdio.h>

int main() {
    int N;
    int reservations[21]; // 21인승이므로 최대 21개의 좌석 예약이 가능하다.
    int counts[21];
    int *p_res, *p_count, *p_end;
    int isDuplicated = 0; // 중복 여부를 나타내는 플래그

    // 우선 승객의 수인 N을 입력을 받는다.
    scanf("%d", &N);

    // 최소 5명이상 예약을 해야 버스가 운행을 한다.
    if (N < 5) {
        printf("-1\n");
        return 0;
    }

    // 카운트 배열 초기화
    for (p_count = counts; p_count < counts + 21; p_count++) {
        *p_count = 0;
    }

    // 좌석 예약에 중복이 있는 경우
    p_end = reservations + N; // 끝 포인터 설정
    for (p_res = reservations; p_res < p_end; p_res++) {
        scanf("%d", p_res);
        *(counts + (*p_res - 1)) += 1;
    }

    // 중복 예약된 좌석 번호와 예약 중복 횟수
    for (p_res = reservations; p_res < p_end; p_res++) {
        if (*(counts + (*p_res - 1)) > 1) {
            printf("%d %d\n", *p_res, *(counts + (*p_res - 1)));
            *(counts + (*p_res - 1)) = 0; // 출력한 번호는 다시 중복되지 않도록 카운트를 0으로 설정
            isDuplicated = 1;
        }
    }

    // 중복이 없으면 다음과 같이 출력한다.
    if (!isDuplicated) {
        printf("0\n");
    }

    return 0;
}
