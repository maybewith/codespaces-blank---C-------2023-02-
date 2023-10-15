#include <stdio.h>
#include <string.h>

// check_w 함수: 주어진 문자열 범위 내에서 "영어 알파벳과 공백을 제외한 문자"의 개수를 반환
int check_w(char* p, char* q) {
    int cnt = 0;
    char* t;

    // p에서 q까지의 문자열 범위를 탐색하되, 문자열의 끝('\0')에 도달하면 중단
    for (t = p; (t <= q && *t != '\0'); t++) {
        // 소문자인 경우 넘어감
        if (*t >= 'a' && *t <= 'z') {
            continue;
        }
        // 대문자인 경우 넘어감
        else if (*t >= 'A' && *t <= 'Z') {
            continue;
        }
        // 공백인 경우 넘어감
        else if (*t == ' ') {
            continue;
        }
        // 나머지 문자는 cnt 증가
        else {
            cnt++;
        }
    }
    return cnt;  // 계산된 cnt 반환
}

int main() {
    // 필요한 변수들을 선언을 해준다.
    int N, M;
    char str[20][100];
    char arr[100];
    int max;
    int cnt = 0;

    int counts[20]; // "영어 알파벳과 공백을 제외한 문자"의 수 저장 배열
    int orders[20]; // 문자열의 입력 순서 저장 배열

    // N과 M 입력 받음
    scanf("%d", &N);
    scanf("%d", &M);
    getchar();

    // N개의 문자열을 입력 받으면서 처리
    for (int i = 0; i < N; i++) {
        gets(arr);
        
        // check_w 함수를 호출하여 M번째 문자까지의 "영어 알파벳과 공백을 제외한 문자" 수 계산
        max = check_w(arr, arr + M - 1);

        // 결과가 0보다 큰 경우 (즉, 알파벳과 공백만으로 이루어진 문자열이 아닌 경우)
        if (max > 0) {
            counts[cnt] = max;
            orders[cnt] = i;
            strcpy(str[cnt], arr);
            cnt++;
        }
    }

    // counts 배열을 기준으로 내림차순 정렬 (동일한 값의 경우 입력 순서로 정렬)
    for (int i = 0; i < cnt - 1; i++) {
        for (int j = 0; j < cnt - 1 - i; j++) {
            // 큰 값으로 정렬하거나, 동일한 경우 입력 순서로 정렬
            if (counts[j] < counts[j + 1] || (counts[j] == counts[j + 1] && orders[j] > orders[j + 1])) {
                int temp_count = counts[j];
                counts[j] = counts[j + 1];
                counts[j + 1] = temp_count;

                int temp_order = orders[j];
                orders[j] = orders[j + 1];
                orders[j + 1] = temp_order;

                char temp_str[100];
                strcpy(temp_str, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp_str);
            }
        }
    }

    // 정렬된 순서대로 결과 출력
    for (int i = 0; i < cnt; i++) {
        printf("%s\n", str[i]);
    }

    return 0;
}
