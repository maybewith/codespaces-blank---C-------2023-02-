#include <stdio.h>

int main() {
    // 변수 선언
    int x, y, z;
    int *px, *py, *pz;
    int tmp;  // tmp는 일반 정수 변수

    // 포인터 초기화
    px = &x;
    py = &y;
    pz = &z;

    // 사용자로부터 값을 입력받아 x, y, z에 저장
    scanf("%d %d %d", px, py, pz);

    // px, py, pz가 가리키는 값들을 교환
    tmp = *px;
    *px = *pz;
    
    *pz = *py;
    *py = tmp;

    // 순서가 바뀐 최종 값을 포인터를 이용하여 출력
    printf("%d %d %d\n", *px, *py, *pz);

    return 0;
}
