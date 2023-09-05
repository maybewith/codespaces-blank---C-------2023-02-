#include <stdio.h>

// 중앙값을 찾아주는 함수
int* mid(int arr[]) {
    int *mid_val;
    if ((arr[0] >= arr[1] && arr[0] <= arr[2]) || (arr[0] >= arr[2] && arr[0] <= arr[1])) {
        mid_val = &arr[0];
    } else if ((arr[1] >= arr[0] && arr[1] <= arr[2]) || (arr[1] >= arr[2] && arr[1] <= arr[0])) {
        mid_val = &arr[1];
    } else {
        mid_val = &arr[2];
    }
    return mid_val;
}

int main() {
    int arr[3];
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &arr[i]);
    }
    int *mid_value = mid(arr);
    printf("%d\n", *mid_value);
    return 0;
}
