#include <stdio.h>

// 날짜 구조체를 만든다.
struct date{
    int year, month, day;
};

// 인자: 두 개의 구조체 변수의 주소 (포인터)
struct date* select_min(struct date* d1, struct date* d2) {
    // 두 날짜 중 더 빠른 날짜를 조건문을 통해서 구한다.
    if (d1->year < d2->year) return d1;
    if (d1->year > d2->year) return d2;
    if (d1->month < d2->month) return d1;
    if (d1->month > d2->month) return d2;
    if (d1->day < d2->day) return d1;

    // 두 날짜 중 더 빠른 날짜를 나타내는 구조체 변수의 주소 (값이 아님)
    return d2;
}

int main() {
    // 사용해야하는 변수들을 선언을 한다.
    struct date d1, d2;
    struct date* earlier;

    // year/month/day 형식의 두 날짜를 입력 받는다.
    scanf("%d/%d/%d", &d1.year, &d1.month, &d1.day);
    scanf("%d/%d/%d", &d2.year, &d2.month, &d2.day);

    // 두 날짜 중 더 빠른 날짜를 찾는다.
    earlier = select_min(&d1, &d2);

    // 두 날짜 중 더 빠른 날짜를 같은 형식으로 출력한다.
    printf("%d/%d/%d\n", earlier->year, earlier->month, earlier->day);
    
    return 0;
}
