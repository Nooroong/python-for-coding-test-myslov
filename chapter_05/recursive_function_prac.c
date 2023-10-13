#include <stdio.h>

/*
1부터 99까지 호출합니다가 출력되고,
그 뒤로는 99부터 1까지 종료합니다가 출력될듯.
*/

void recursive_fun(int i);

int main(void)
{
    recursive_fun(1);
    return 0;
}

void recursive_fun(int i)
{
    if(i == 100)
        return;
    
    printf("%d번째 재귀함수에서 %d번째 재귀함수를 호출합니다.\n", i, i+1);
    recursive_fun(i+1);
    printf("%d번째 재귀함수를 종료합니다.\n", i);
}