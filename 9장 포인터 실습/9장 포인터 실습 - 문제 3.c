#include <stdio.h> 

int main() {  
    // 정수를 저장할 배열 선언, 포인터 p 선언 및 초기화, N은 입력 받을 정수의 개수, count는 실제로 입력 받은 정수의 개수
    int ar[50];  
    int *p = ar;  
    int N, count = 0;  

    // 정수 N을 입력 받음 (배열에 입력할 정수의 개수)
    scanf("%d", &N);  
    
    // N개의 정수를 입력받아 배열에 저장하고, 0이 입력되면 입력 종료
    for (p = ar; p < ar + N; p++) {  
        // 정수를 입력 받아 현재 p가 가리키는 배열 원소에 저장
        scanf("%d", p);  

        // 입력 받은 정수가 0이면 for 루프를 빠져나감
        if (*p == 0) break;  

        // 정수를 하나 입력받았으므로 count 증가
        count++;  
    }

    // 실제로 입력받은 정수의 개수 출력
    printf("%d\n", count);  

    // 프로그램 종료
    return 0;  
}

