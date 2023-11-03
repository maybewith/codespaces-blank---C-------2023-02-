// Online C compiler to run C program online
#include <stdio.h>

#include <string.h>

// 학생의 구조체를 선언한다.
struct student {
  // 학생의 이름 저장 변수
  char name[21];

  // 성적을 저장할 변수
  int kor, eng, math;

  // 학생의 평균
  double avg;
};

// 중간 등수 학생의 성적이 더 높은 배열의 주소를 변환
struct student* select_out(struct student *s1, struct student *s2, int N) {
    int middle = N / 2;
    return (s1+middle)->avg > (s2+middle)->avg ? s1 : s2;
}

// 정렬을 해주는 함수
void sort_score(struct student *str, int n) {
    // 반복문을 통해서 버블 정렬을 구현해보자
    for (struct student * p1 = str; p1 < str + n - 1; p1++) {
      for (struct student * p2 = p1 + 1; p2 < str + n; p2++) {
        // 평균이 더 큰 경우

        if (p1->avg < p2->avg || (p1->avg == p2->avg && p1->kor < p2->kor) ||
          (p1->avg == p2->avg && p1->kor == p2->kor && p1->eng < p2->eng)) {
          
          struct student temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        }
      }
    }
}
    // 입력을 받아주는 함수
void read_data(struct student * str, int n) {
      // 학생 정보를 입력을 받는다.
      struct student * p;
      for (p = str; p < str + n; p++) {
        // 입력 받기
        scanf("%s %d %d %d", p -> name, & p -> kor, & p -> eng, & p -> math);

        // 평균을 계산하기
        double tmp = p -> kor + p -> eng + p -> math;
        tmp = tmp / 3;
        p -> avg = tmp;
      }
}

int main() {
      // 입력을 받을 개수를 입력을 받는다.
      int n;
      scanf("%d", &n);

      // 학생들의 성적을 입력을 받는다.
      struct student str1[n];
      struct student str2[n];
      read_data(str1, n);
      read_data(str2, n);

      // 배열을 정렬을 시켜준다.
      sort_score(str1, n);
      sort_score(str2, n);

    // select_out을 통해서 중간 등수가 성적 높은 배열 구하기
    struct student *str;
    str = select_out(str1, str2,n);

    for (int i = 0; i < n; i++){
        printf("%s %d %d %d %.1lf\n",(str+i)->name,(str+i)->kor,(str+i)->eng,(str+i)->math,(str+i)->avg);
    }
    
      return 0;
}