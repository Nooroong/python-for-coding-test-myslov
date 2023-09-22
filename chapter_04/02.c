#include <stdio.h>

/*
체스 말이 움직일 수 있는 경우의 수(8가지)를 일일이 계산.
*/

int main(void)
{
    int row, col;
    int cnt;

    scanf("%c%d", &col, &row);
    col -= 96;
    
    cnt = 0;

    if(col+2 <= 8 && row+1 <= 8) cnt++;
    if(col+2 <= 8 && row-1 >= 1) cnt++;
    if(col-2 >= 1 && row+1 <= 8) cnt++;
    if(col-2 >= 1 && row-1 >= 1) cnt++;
    
    if(row+2 <= 8 && col+1 <= 8) cnt++;
    if(row+2 <= 8 && col-1 >= 1) cnt++;
    if(row-2 >= 1 && col+1 <= 8) cnt++;
    if(row-2 >= 1 && col-1 >= 1) cnt++;

    printf("%d", cnt);

    return 0;
}