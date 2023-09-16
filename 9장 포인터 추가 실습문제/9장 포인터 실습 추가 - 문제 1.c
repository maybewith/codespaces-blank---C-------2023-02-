#include <stdio.h>

// 함수 원형: void input(int *p, int M)
void input(int *p, int M) {
    // p는 배열의 시작 주소이다
    int *ptr = p;

    // 정수 M개를 입력받아 p가 가리키는 배열에 저장한다
    for (ptr=p; ptr < p+M; ++ptr) {
        scanf("%d", ptr);
    }
}

// 인자 : int형 포인터 p와 int형 정수 M 
int* sel_max(int *p, int M) {
    // 최대의 개수와 그 숫자를 기억하기 위한 변수
    int count, maxCount = 0;

    // p는 배열의 시작 주소이다
    int *maxPtr = p;
    int *ptr1, *ptr2;
    
    // 배열에 저장된 M개의 정수 중 중복 횟수가 가장 높은 정수를 선택
    for (ptr1 = p; ptr1 < p + M; ++ptr1) {
        count = 0;
        for (ptr2 = p; ptr2 < p + M; ++ptr2) {
            if (*ptr1 == *ptr2) {
                ++count;
            }
        }

        // 최다 중복 정수가 둘 이상인 경우, 가장 처음에 나타나는 정수를 선택 한다.
        if (count > maxCount) {
            maxCount = count;
            maxPtr = ptr1;
        }
    }

    // 선택된 정수가 저장된 배열 원소의 주소
    return maxPtr;
}

// 함수 원형: void output(int *p, int N)
void output(int *p, int N) {
    // p는 배열의 시작 주소이다
    int *ptr = p;

    //  배열에 저장된 정수 N개를 출력한다
    for (ptr=p; ptr < p+N; ++ptr) {
        printf("%d ", *ptr);
    }
    printf("\n");
}

// main 함수는 아래와 같으며, 내용 수정이 불가하다.
int main(void) {
    int in[100], out[100], *max, i, N, M;

    scanf("%d %d", &N, &M);
    for (i = 0; i < N; ++i) {
        input(in, M);
        max = sel_max(in, M);
        out[i] = *max;
    }
    output(out, N);
    return 0;
}
