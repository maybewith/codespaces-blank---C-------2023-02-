#include <stdio.h> 

int main() {
    // 문자 10개를 저장할 배열와 문자 포인터 선언
    char ch[10];  
    char *p, *q;  

    // 가장 빈번히 나타나는 문자의 빈도수를 저장할 변수와 그 문자를 저장할 변수
    int max_count = 0;  
    char max_char = 0;  

    // 10개의 문자 입력
    for (p = ch; p < ch + 10; p++) {
        // 공백을 무시하고 문자를 입력받아 ch 배열에 저장
        scanf(" %c", p);  
    }

    // 빈도수 체크
    for (p = ch; p < ch + 10; p++) {
        // 현재 문자의 빈도수를 저장할 변수
        int count = 0;  
        for (q = ch; q < ch + 10; q++) {
            // 현재 문자와 비교 문자가 같으면
            if (*p == *q) {
                // 빈도수 증가  
                count++;  
            }
        }

        // 빈도수가 현재 최대 빈도수보다 높은 경우
        if (count > max_count) {
            // 최대 빈도수 업데이트 및 해당 문자 저장
            max_count = count;  
            max_char = *p;  
        }
    }

    // 결과 출력 (가장 빈번히 나타나는 문자와 그 빈도수 출력)
    printf("%c %d\n", max_char, max_count); 

    // 프로그램 종료
    return 0;  
}

