#include <stdio.h>
#include <string.h>

int main() {
    // 두 개의 문자열 A, B를 저장하기 위한 배열
    char inputA[21] = "", inputB[21] = ""; 

    // 문자열 A와 B를 입력 받는다.
    gets(inputA);  // 사용자로부터 문자열 A를 입력받음
    gets(inputB);  // 사용자로부터 문자열 B를 입력받음

    // 복사를 할 문자열을 선언하고 복사를 한다.
    char transformedA[210] = "", transformedB[210] = "";
    strcpy(transformedA, inputA); 
    strcpy(transformedB, inputB); 

    int charIndex = 0;
    // 문자열 A와 B에서 가장 첫번째로 다른 문자간의 차이를 구한다.
    int difference;
    while (1)
    {
        difference = inputA[charIndex] - inputB[charIndex];
        if (difference < 0) difference *= (-1); // 차이값의 절대값을 구한다.
        // 대문자 또는 소문자일 때 차이를 찾는다.
        if (('A' <= inputA[charIndex] && inputA[charIndex] <= 'Z') || 
            ('A' <= inputB[charIndex] && inputB[charIndex] <= 'Z') || 
            ('a' <= inputA[charIndex] && inputA[charIndex] <= 'z') || 
            ('a' <= inputB[charIndex] && inputB[charIndex] <= 'z')) 
            break;
        charIndex++;
    }

    // 다음 과정을 위해서 필요한 변수들을 선언을 한다.
    char repeatedA[21][11] = { "" }, repeatedB[21][11] = { "" }, buffer[21] = "";
    int index = 0;
    int num;

    // 문자열 A를 변환한다.
    for (int i = 0; i < strlen(inputA); i++)
    {
        // 대문자일 경우 N번째 뒤 문자로 변경
        if ('A' <= inputA[i] && inputA[i] <= 'Z') 
            transformedA[i] += difference;
        // 소문자일 경우 N번째 앞 문자로 변경
        else if ('a' <= inputA[i] && inputA[i] <= 'z') 
            transformedA[i] -= difference;
        // 숫자일 경우 해당 숫자 번째의 알파벳 대문자를 N번 반복
        else if ('1' <= inputA[i] && inputA[i] <= '9')
        {
            if ('0' <= inputA[i + 1] && inputA[i + 1] <= '9') 
            {
                // 두 자리 수가 있는 경우
                num = (int)((inputA[i] - '0') * 10 + (inputA[i + 1] - '0'));
                if (num >= 27)
                {
                    // 숫자가 27 이상인 경우
                    num = (int)(inputA[i] - '0');
                }
                else
                    i++; // 다음 문자로 이동하여 두 자리 수를 건너뛴다.
            }
            else 
            {
                // 한 자리 숫자인 경우
                num = (int)(inputA[i] - '0');
            }

            // 반복 횟수에 따라 알파벳을 생성하고 repeatedA 배열에 저장한다.
            for (int j = 0; j < difference; j++)
                repeatedA[index][j] = 'A' + (num - 1); 
            index++; // 다음 반복 문자열을 처리하기 위해 인덱스 증가
        }
        // 그 외의 경우 공백으로 변경
        else if (inputA[i] != '0') 
        { 
            transformedA[i] = ' ';
        }
    }

    // 숫자에 해당하는 부분을 문자로 치환한다.
    for (int i = 0; i < strlen(transformedA); i++) 
    {   
        // transformedA에서 숫자를 발견한 경우
        if ('1' <= transformedA[i] && transformedA[i] <= '9') 
        { 
            // 반복할 알파벳이 A부터 H 사이인 경우 
            if (repeatedA[charIndex][0] >= 'A' && repeatedA[charIndex][0] < 'A' + 9)
                strcpy(buffer, transformedA + i + 1);
            else // 반복할 알파벳이 I부터 Z 사이인 경우
                strcpy(buffer, transformedA + i + 2);
            // transformedA에서 숫자를 반복한 알파벳으로 대체
            strcpy(transformedA + i, repeatedA[charIndex]); 

            // 다음 반복 알파벳으로 이동
            charIndex++;
            
            // 변환된 문자열 뒤에 나머지 부분을 다시 추가
            strcat(transformedA, buffer);  
        }
    }

    // 문자열 B를 변환한다.
    index = 0;
    for (int i = 0; i < strlen(inputB); i++) 
    {
        // 대문자일 경우 N번째 뒤 문자로 변경
        if ('A' <= inputB[i] && inputB[i] <= 'Z')
            transformedB[i] += difference;
        // 소문자일 경우 N번째 앞 문자로 변경
        else if ('a' <= inputB[i] && inputB[i] <= 'z')  
            transformedB[i] -= difference; 
        // 숫자일 경우 해당 숫자 번째의 알파벳 대문자를 N번 반복
        else if ('1' <= inputB[i] && inputB[i] <= '9') 
        {
            if ('0' <= inputB[i + 1] && inputB[i + 1] <= '9') 
            {
                // 두 자리 수가 있는 경우
                num = (int)((inputB[i] - '0') * 10 + (inputB[i + 1] - '0')); 
                if (num >= 27) 
                { 
                    // 숫자가 27 이상인 경우
                    num = (int)(inputB[i] - '0');
                }
                else
                    i++; // 다음 문자로 이동하여 두 자리 수를 건너뛴다.
            }
            else
            {
                // 한 자리 숫자인 경우
                num = (int)(inputB[i] - '0'); 
            }

            // 반복 횟수에 따라 알파벳을 생성하고 repeatedB 배열에 저장한다.
            for (int j = 0; j < difference; j++)
                repeatedB[index][j] = 'A' + (num - 1); 
            index++; // 다음 반복 문자열을 처리하기 위해 인덱스 증가
        }
        // 그 외의 경우 공백으로 변경
        else if (inputB[i] != '0') 
        { 
            transformedB[i] = ' ';
        }
    }

    // 숫자에 해당하는 부분을 문자로 치환한다.
    charIndex = 0;
    for (int i = 0; i < strlen(transformedB); i++)
    {
        if ('1' <= transformedB[i] && transformedB[i] <= '9') 
        {
            // transformedB에서 숫자를 발견한 경우
            if (repeatedB[charIndex][0] >= 'A' && repeatedB[charIndex][0] < 'A' + 9)
                // 반복할 알파벳이 A부터 H 사이인 경우
                strcpy(buffer, transformedB + i + 1);
            else
                // 반복할 알파벳이 I부터 Z 사이인 경우
                strcpy(buffer, transformedB + i + 2);

            strcpy(transformedB + i, repeatedB[charIndex]); // transformedB에서 숫자를 반복한 알파벳으로 대체
            charIndex++; // 다음 반복 알파벳으로 이동
            strcat(transformedB, buffer); // 변환된 문자열 뒤에 나머지 부분을 다시 추가
        }
    }

    // A를 B로 변경 가능한지, B를 A로 변경 가능한지 판단한다.
    int compareAtoB = strcmp(transformedA, inputB);
    int compareBtoA = strcmp(transformedB, inputA);
    int result;
    if (compareAtoB == 0 && compareBtoA == 0) result = 3;  // 양쪽 모두 변경 가능한 경우
    else if (compareBtoA == 0) result = 2;  // B를 A로 변경 가능한 경우
    else if (compareAtoB == 0) result = 1;  // A를 B로 변경 가능한 경우
    else result = 0;  // 둘 다 변경 불가능한 경우

    printf("%d", result);  // 결과를 출력
    return 0;
}
