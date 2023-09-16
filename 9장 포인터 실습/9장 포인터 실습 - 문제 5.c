#include <stdio.h>  

int main() {  
    // 점수를 저장할 arr 배열과 등수를 저장할 rank 배열 선언
    int arr[5], rank[5];  

    // 정수 포인터 p와 q 선언
    int *p, *q, *m;  
    m=rank;

    // 5개의 정수 입력
    for (p = arr; p < arr + 5; p++) {  
        // 정수를 입력받아 arr 배열에 저장
        scanf("%d", p);  
    }

    // 등수 초기화
    for (p = rank; p < rank + 5; p++) {  
        // 모든 학생의 초기 등수를 1로 설정
        *p = 1;  
    }

    // 등수 계산
    for (p = arr; p < arr + 5; p++) {  
        for (q = arr; q < arr + 5; q++) {  
            // p가 가리키는 점수가 q가 가리키는 점수보다 작을 경우
            if (*p < *q) {
                // 해당 학생의 등수 증가  
                *(m+p - arr)++;  
            }
        }
    }

    // 결과 출력
    for (p = arr, q = rank; p < arr + 5; p++, q++) {  
        // 점수와 그에 따른 등수 출력
        printf("%d=r%d ", *p, *q);  
    }
    
    // 프로그램 종료
    return 0;  
}

