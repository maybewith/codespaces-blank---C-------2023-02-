#include <stdio.h>

int passengerN(int n) {
    // 반환 값: 승객 수가 부족하면 –1, 승객 수가 충분하면 0을 반환한다.
    if (n < 5) {
        return -1;
    } else {
        return 0;
    }
}

int changeseat(int *ar) {
    // 1~21 사이의 숫자들 중 배열에 존재하지 않으면서 가장 작은 숫자를 찾아준다.
    for (int i = 1; i <= 21; i++) {
        int *p;
        int found = 0;
        for (p = ar; p < ar + 21; p++) {
            if (*p == i) {
                found = 1;
                break;
            }
        }
        if (!found) {
            // 찾아낸 가장 작은 숫자를 반환한다.
            return i;
        }
    }
    return -1;
}

void rebooking(int *ar) {
    // 중복된 좌석 번호가 존재하는지 확인하고
    // 좌석 번호를 빠른 번호의 빈 좌석 번호로 대체한다.
    for (int *p1 = ar; p1 < ar + 21; p1++) {
        for (int *p2 = p1 + 1; p2 < ar + 21; p2++) {
            if (*p1 == *p2) {
                // changeseat 함수를 호출한다.
                *p2 = changeseat(ar);
            }
        }
    }
}

int main() {
    int N;
    int reservations[21];
    int result;
    int *p;

    // 승객의 숫자를 입력 받는다
    scanf("%d", &N);

    // 승객들이 차례로 버스 좌석 번호를 예약한다. (중복 가능)
    for (p = reservations; p < reservations + N; p++) {
        scanf("%d", p);
    }

    // passengerN 함수를 호출하여 승객 수가 부족한지 확인한다
    result = passengerN(N);

    // 승객 수가 부족한지 여부를 출력한다. (부족: -1. 충분: 0) 
    printf("%d\n", result);

    // 승객 수가 부족하면 이후 프로그램을 실행시키지 않는다. 
    if (result == 0) {
        // 승객 수가 충분하면 최종 좌석 예약 결과를 출력한다.
        rebooking(reservations);
        for (p = reservations; p < reservations + N; p++) {
            printf("%d ", *p);
        }
        printf("\n");
    }

    return 0;
}
