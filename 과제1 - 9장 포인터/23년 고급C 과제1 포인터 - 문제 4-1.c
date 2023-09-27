#include <stdio.h>

int main() {
    int a[10], b[10]; // 선언
    int *p;
    int count_a = 0, count_b = 0;
    int max_a = -1, min_a = 101, max_b = -1, min_b = 101; // -1과 101로 초기화
    int score;

    // 101호 점수 입력
    while(1) {
        scanf("%d", &score);
        if(score == -1) break;
        *(a + count_a) = score;
        count_a++;
    }

    // 102호 점수 입력
    while(1) {
        scanf("%d", &score);
        if(score == -1) break;
        *(b + count_b) = score;
        count_b++;
    }

    // 101호 최고 점수 및 최저 점수 탐색
    for(p = a; p < a + count_a; p++) {
        if(*p > max_a) max_a = *p;
        if(*p < min_a) min_a = *p;
    }

    // 102호 최고 점수 및 최저 점수 탐색
    for(p = b; p < b + count_b; p++) {
        if(*p > max_b) max_b = *p;
        if(*p < min_b) min_b = *p;
    }

    // 출력
    printf("%d %d\n", count_a, count_b);
    printf("%d %d\n", (max_a > max_b ? max_a : max_b), (min_a < min_b ? min_a : min_b));

    return 0;
}
