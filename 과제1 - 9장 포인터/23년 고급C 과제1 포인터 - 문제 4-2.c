#include <stdio.h>

// swap 함수: 두 정수 포인터가 가리키는 값을 교환
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a[30] = {0}, b[10] = {0};
    int na = 10, nb = 0;  // 초기 시작 지점은 10으로 설정합니다.
    int *p;
    int acount=0,bcount=0; // 101호와 102호에서 응시한 학생의 수

    // 101호에서의 점수 입력
    // 입력은 -1이 나올 때까지 진행
    for (p = a + 10; p < a + 30; p++) {
        scanf("%d", p);
        if (*p == -1) {
            break;
        }
        na++;
        acount++;
    }

    // 102호에서의 점수 입력
    // 입력은 -1이 나올 때까지 진행
    for (p = b; p < b + 10; p++) {
        scanf("%d", p);
        if (*p == -1) {
            break;
        }
        nb++;
        bcount++;
    }

    // 102호의 점수를 101호의 점수 배열 a에 추가
    int *q;
    p = a + 10 + acount;
    for (q = b; q < b + bcount; q++, p++) {
        *p = *q;
    }
    na += nb;

    // 내림차순 정렬 및 출력
    for (int i = 10; i < na - 1; i++) {
        for (p = a + 10; p < a + na - 1; p++) {
            if (*p < *(p+1)) {
                swap(p, p+1);
            }
        }
    }
    
    // 가장 높은 점수 n개 출력
    for (p = a+10; p < a+10+acount; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    // 오름차순 정렬 및 출력
    for (int i = 10; i < na - 1; i++) {
        for (p = a + 10; p < a + na - 1; p++) {
            if (*p > *(p+1)) {
                swap(p, p+1);
            }
        }
    }
    
    // 가장 낮은 점수 m개 출력
    for (p = a+10; p < a+10+bcount; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    return 0;
}
