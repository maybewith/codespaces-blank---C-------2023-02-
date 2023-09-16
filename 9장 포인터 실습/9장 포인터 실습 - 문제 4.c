#include <stdio.h>

// 정렬 함수
void sort(int *start, int *end) {
    // 정렬에 필요한 변수들을 선언한다
    int *i, *j, temp;
    
    // 반복문을 통해서 중앙에 중앙값을 넣어준다
    for(i = start; i < end; i++) {
        for(j = i + 1; j <= end; j++) {
            // 비교를 하여 바꿔준다
            if(*i > *j) {
                temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}

int main() {
    // 필요한 배열과 포인터를 선언한다
    int x[3];
    int *p;
    
    // 사용자 입력 받기
    for(p = x; p < x + 3; p++) {
        scanf("%d", p);
    }
    
    // 배열 정렬
    sort(x, x + 2);
    
    // 중앙값 출력
    printf("%d", *(x + 1));
    
    return 0;
}
