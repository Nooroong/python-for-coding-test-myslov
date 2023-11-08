#include <stdio.h>
#include <stdlib.h>

/*
56m 50s
0부터 떡의 최대길이에 대해 어느 지점을 잘라야하는지 이진탐색을 이용해 정한다.
*/

int BinarySearch(int arr[], int left, int right, int target);
int CutSum(int arr[], int height); // height 지점을 잘랐을 때 남는 떡의 길이 총합.

int main(void)
{
    int n, m;
    int h;
    unsigned int * tteok; // 떡의 개별 높이를 저장
    unsigned int maxTteokLen = 0; // 가장 길이가 긴 떡의 길이
    int i;

    scanf("%d %d", &n, &m); // 떡의 개수, 요청한 떡의 길이
    tteok = (unsigned int*)malloc(sizeof(unsigned int) * n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &tteok[i]);
        if(tteok[i] > maxTteokLen)
            maxTteokLen = tteok[i];
    }

    printf("%d", BinarySearch(tteok, 0, maxTteokLen, m));

    return 0;
}

int BinarySearch(int arr[], int left, int right, int target)
{
    int mid;
    int height;

    while(left <= right)
    {
        mid = (left+right)/2;

        if(CutSum(arr, mid) == target)
            return mid;
        else if(CutSum(arr, mid) < target)
            right =  mid-1;
        else // '적어도' m만큼 떡을 얻어야하므로 일단 떡 길이가 목푯값보다 크다면 자르는 위치를 기억해둔다.
        {
            height = mid;
            left = mid+1;
        }
    }

    return height;
}

int CutSum(int arr[], int height)
{
    int len = _msize(arr) / sizeof(int);
    int i;
    unsigned int sum = 0;

    for(i = 0; i < len; i++)
    {
        if(arr[i] > height)
            sum += arr[i] - height;
    }

    return sum;
}