#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 해당 배열의 해당 인덱스가 나타내는 위치에 ‘+’ 혹은 ‘*' 를 삽입한다.
void StringAdd(char arr[], char ch, int index) {
    int len = strlen(arr);  // "문자열 길이 구하기 표준 문자열 함수" 사용
    for (int i = len; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    // 해당 인덱스가 나타내는 위치에 ‘+’ 혹은 ‘*' 를 삽입한다.
    arr[index] = ch;
    arr[len + 1] = '\0';
}

// 숫자 문자를 정수로 변환한다.
int Convertor(char x) {
    return x - '0';
}

int main() {
    char str[200];  // Maximum size with the possible insertions of '*' or '+'
    
    // 문자열을 사용자로부터 입력 받아 char형 배열 str[ ]에 저장한다.
    gets(str);

    int len = strlen(str);  // "문자열 길이 구하기 표준 문자열 함수" 사용
    for (int i = 0; i < len - 1; i++) {
        int num1 = Convertor(str[i]);
        int num2 = Convertor(str[i + 1]);

        // 홀수가 연속되는 경우에 StringAdd() 함수를 호출하여, 두 홀수 사이에 ‘+’를 추가한다.
        if (num1 % 2 == 1 && num2 % 2 == 1) {
            StringAdd(str, '+', i + 1);
            len++;  // +에 의해서 늘려준다.
            i++;
        } 
        // 짝수가 연속되는 경우에도 ①과 비슷한 방법으로 처리한다.
        else if (num1 % 2 == 0 && num2 % 2 == 0) {
            StringAdd(str, '*', i + 1);
            len++;  // *에 의해서 늘려준다.
            i++;
        }
    }

    // 문자열을 화면으로 출력한다.
    printf("%s\n", str);

    return 0;
}
