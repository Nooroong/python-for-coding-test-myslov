#include <stdio.h>
#include <stdlib.h>

/*
30m 00s
병합정렬: 데이터의 개수가 최대일 때 대략 2천만번의 연산.
이진탐색: log 1,000,000은 대략 20. m이 10만일 때는 탐색을 위해 총 200만번의 연산을 수행해야함.
→ 계수정렬을 이용해 더 간단히 해결할 수 있음.

완전탐색의 경우 최악의 경우 100만번 * 10만번.
*/

int main(void)
{
    int n, m;
    int stock[1000001] = {0};
    int * require;
    int i, j;
    int tmp;

    int left, right, mid;


    // 입력받기
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        stock[tmp] = 1;
    }


    scanf("%d", &m);
    require = (int*)malloc(sizeof(int) * m);
    for(i = 0; i < m; i++) scanf("%d", &require[i]);


    // 출력
    for(i = 0; i < m; i++)
    {
        if(stock[require[i]] >= 1)
            printf("yes ");
        else
            printf("no ");
    }


    return 0;
}