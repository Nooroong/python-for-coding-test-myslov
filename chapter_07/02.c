#include <stdio.h>
#include <stdlib.h>

/*
30m 00s
��������: �������� ������ �ִ��� �� �뷫 2õ������ ����.
����Ž��: log 1,000,000�� �뷫 20. m�� 10���� ���� Ž���� ���� �� 200������ ������ �����ؾ���.
�� ��������� �̿��� �� ������ �ذ��� �� ����.

����Ž���� ��� �־��� ��� 100���� * 10����.
*/

int main(void)
{
    int n, m;
    int stock[1000001] = {0};
    int * require;
    int i, j;
    int tmp;

    int left, right, mid;


    // �Է¹ޱ�
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        stock[tmp] = 1;
    }


    scanf("%d", &m);
    require = (int*)malloc(sizeof(int) * m);
    for(i = 0; i < m; i++) scanf("%d", &require[i]);


    // ���
    for(i = 0; i < m; i++)
    {
        if(stock[require[i]] >= 1)
            printf("yes ");
        else
            printf("no ");
    }


    return 0;
}