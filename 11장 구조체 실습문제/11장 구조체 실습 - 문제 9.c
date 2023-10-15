#include <stdio.h>

// 시험 결과 정보를 나타내는 result 구조체를 정의하여 사용하시오.
struct result{
    // 가장 높은 점수를 저장하는 정수형 변수, 가장 낮은 점수를 저장하는 정수형 변수, 시험
    // 통과 여부를 저장하는 문자형 변수, 합격 기준 점수차를 저장하는 정수형 변수, 가장 높은
    // 점수와 가장 낮은 점수의 차이를 저장하는 정수형 변수
    int highest;
    int lowest;
    char passOrFail;
    int passMargin;
    int scoreDifference;
};

// 인자: 구조체 포인터
void passorfail(struct result* r) {
    r->scoreDifference = r->highest - r->lowest;

    // 시험 통과 여부를 계산하여 ‘P’ 혹은 ‘F’를 저장
    if (r->scoreDifference <= r->passMargin)
        r->passOrFail = 'P';
    else
        r->passOrFail = 'F';

    // 반환 값: 없음
}

int main() {
    // 시험 결과 정보를 저장할 result 구조체 선언
    struct result res;

    // 한 학생의 시험 결과 정보(가장 높은 점수, 가장 낮은 점수, 시험 통과
    // 여부, 합격 기준 점수차, 점수차)를 입력 받는다
    scanf("%d %d %d", &res.highest, &res.lowest, &res.passMargin);
    
    // passorfail 함수를 호출하여, 이 학생의 시험 통과 여부 판단하기
    passorfail(&res);
    
    // 이 학생의 점수차와 시험 통과 여부를 출력하기
    printf("%d %c\n", res.scoreDifference, res.passOrFail);
    return 0;
}
