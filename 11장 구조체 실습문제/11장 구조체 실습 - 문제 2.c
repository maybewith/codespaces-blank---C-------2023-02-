#include <stdio.h>

// 구조체를 이용하여서 현재 시각을 표현한다.
struct Time {
    int hours, minutes, seconds;
};

int main() {
    // 필요한 변수를 선언한다.
    struct Time t1, t2, diff;

    // 사용자로부터 2개의 시각을 입력 받는다.
    scanf("%d %d %d", &t1.hours, &t1.minutes, &t1.seconds);
    scanf("%d %d %d", &t2.hours, &t2.minutes, &t2.seconds);

    // 두 시각 사이의 차이를 계산한다.
    diff.seconds = t2.seconds - t1.seconds;
    diff.minutes = t2.minutes - t1.minutes;
    diff.hours = t2.hours - t1.hours;

    // 시간이 음수로 나오지 않기 위해서 계산을 추가로 한다.
    if (diff.seconds < 0) {
        diff.seconds += 60;
        diff.minutes--;
    }
    // 시간이 음수로 나오지 않기 위해서 계산을 추가로 한다.
    if (diff.minutes < 0) {
        diff.minutes += 60;
        diff.hours--;
    }

    // 두 시각 사이의 차이를 계산하여 출력한다.
    printf("%d %d %d\n", diff.hours, diff.minutes, diff.seconds);
    
    return 0;
}
