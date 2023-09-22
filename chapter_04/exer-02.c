#include <stdio.h>

/*
데이터의 수가 많지 않으므로 완전탐색을 이용.
나머지 연산과 나누기 연산을 적절히 활용해 3이 틀어간 시간의 수를 구한다.
*/

int main(void)
{
    int n;
    int cnt;
    int t, m, s;
    scanf("%d", &n);

    cnt = 0;
    for(t = 0; t <= n; t++)
    {
        for(m = 0; m <= 59; m++)
        {
            for(s = 0; s <= 59; s++)
            {
                if(t % 10 == 3 || t / 10 == 3||
                   m % 10 == 3 || m / 10 == 3 ||
                   s % 10 == 3 || s / 10 ==3)
                    cnt++;
            }
        }
    }

    printf("%d", cnt);

    return 0;
}