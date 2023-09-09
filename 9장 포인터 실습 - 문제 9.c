#include <stdio.h>

// 중앙값을 찾아주는 함수
int* mid(int *arr) {
    // 저장할 변수를 선언한다
    int *mid_val;

    // 만약 첫번째거라면, 두번째라면, 세번째라면.....
    if ((*arr >= *(arr+1) && *arr <= *(arr+2)) || (*arr >= *(arr+2) && *arr <= *(arr+1))) {
        mid_val = arr;
    } else if ((*(arr+1) >= *arr && *(arr+1) <= *(arr+2)) || (*(arr+1) >= *(arr+2) && *(arr+1) <= *arr)) {
        mid_val = arr+1;
    } else {
        mid_val = arr+2;
    }

    // 값을 반환을 해준다
    return mid_val;
}

int main() {
    // 필요한 포인터와 배열을 선언한다
    int *p;
    int arr[3];

    // 입력을 받는다
    for (p = arr; p < arr + 3; p++) {
        scanf("%d", p);
    }

    // 중앙값을 찾아주는 함수에 배열을 넣는다 
    int *mid_value = mid(arr);

    // 값을 출력을 해준다
    printf("%d\n", *mid_value);

    return 0;
}
