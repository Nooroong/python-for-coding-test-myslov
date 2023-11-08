#include <stdio.h>

/*
58m 00s

완탐으로 풀면 시간이 너무 오래 걸릴 것 같다 → DP로 접근해본다.
가로 길이가 i인 경우,
1) 가로 길이가 i-1인 경우에서 1*2 덮개를 씌우는 경우 한 가지만 존재한다.
2) 가로 길이가 i-2인 경우에서 2*2 덮개 1개, 2*1 덮개 2개를 씌우는 두 가지 경우가 존재한다.
(1*2 덮개를 2개 씌우는 경우는 이미 1번에서 고려했다.)
따라서 점화식은 Ai = A(i-1) + A(i-2) * 2가 된다.
*/

int d[1001] = {0}; // DP Table

int main(void)
{
    int n; // 바닥의 가로 길이. 바닥의 크기는 n * 2.
    int i;

    scanf("%d", &n);

    d[1] = 1;
    d[2] = 3;

    for(i = 3; i <= n; i++)
        d[i] = d[i-1] + d[i-2]*2;
    

    printf("%d", d[n]);
    
    return 0;
}