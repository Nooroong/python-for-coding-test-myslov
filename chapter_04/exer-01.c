#include <stdio.h>

/*
삼항연산자를 통해 좌표가 유효값을 벗어나지 않도록 해줬다.
*/

int main(void)
{
    int n;
    int x = 1, y = 1; // coordinate
    char direction;

    scanf("%d", &n);
    
    while(scanf("%c", &direction) != EOF)
    {
        switch(direction)
        {
            case 'L':
                y = (y-1)>=1?(y-1):1;
                break;
            case 'R':
                y = (y+1)<=n?(y+1):n;
                break;
            case 'U':
                x = (x-1)>=1?(x-1):1;
                break;
            case 'D':
                x = (x+1)<=n?(x+1):n;
                break;
        }
    }

    printf("%d %d", x, y);


    return 0;
}