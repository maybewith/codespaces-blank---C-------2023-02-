#include <stdio.h>

// 3차원 벡터를 저장할 구조체를 선언 
struct Vector{
    int x, y, z;
};

int main() {
    // 두개의 3차원 벡터(V1, V2)를 입력 받는다.
    struct Vector V1, V2, V3;
    scanf("%d %d %d", &V1.x, &V1.y, &V1.z);
    scanf("%d %d %d", &V2.x, &V2.y, &V2.z);
    
    // 원소별로 곱한 값을 새로운 3차원 벡터 (V3)에 입력 후
    V3.x = V1.x * V2.x;
    V3.y = V1.y * V2.y;
    V3.z = V1.z * V2.z;

    // 곱의 결과와 두 벡터의 내적의 결과를 출력한다.
    printf("%d %d %d\n", V3.x, V3.y, V3.z);
    printf("%d\n",V3.x+V3.y+V3.z);
    
    return 0;
}
