#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) (a)<(b)?(a):(b)

/*
36m 12s
큰 단위가 작은 단위의 배수가 아닌 경우에는 그리디로 문제를 해결할 수 없다.
각 화폐단위로 나눴을 때 몫이 작은 경우를 선택?
*/


int * d; // dp table


int main(void)
{
    int n, m; // n: 화폐 단위의 수. m: 만들어야 하는 금액.
    int * money;
    int i, j;

    d = (int*)malloc(sizeof(int) * (m+1));

    scanf("%d %d", &n, &m);
    money = (int*)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++) scanf("%d", &money[i]);

    d = memset(d, 10001, sizeof(int) * (m+1));
    d[0] = 0; // 0원을 만들기 위해서는 0개의 화폐가 필요하다.

    for(i = 0; i < n; i++)
    {
        for(j = money[i]; j <= m; j++)
        {   
            d[j] = MIN(d[j], d[j-money[i]] + 1);
        }
    }

    printf("%d", d[m]>10000?-1:d[m]);

    return 0;
}