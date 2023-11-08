#include <stdio.h>
#include <stdlib.h>

/*
22m 00s
정렬된 값이 주어지고 O(logN)의 시간복잡도를 요구하므로 일단은 이진탐색으로 해당 값의 아무 위치를 찾는다.
다음으로, 그 위치를 기점으로 좌, 우를 살펴 어디까지 해당 값이 있는지 찾아 개수를 구한다.
*/

int BinarySearch(int arr[], int left, int right, int target);

int main(void)
{
    int n, x;
    int * nums;
    int targetIdx;
    int numOfTarget = 0;
    int i;

    scanf("%d %d", &n, &x);
    nums = (int*)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++) scanf("%d", &nums[i]);

    targetIdx = BinarySearch(nums, 0, n-1, x);

    if(targetIdx != -1)
    {
        i = targetIdx;
        while(nums[i--] == x) numOfTarget++;
        i = targetIdx + 1; // targetIdx위치의 값을 두 번 세지 않도록 여기서는 +1을 해준다.
        while(nums[i++] == x) numOfTarget++;

        printf("%d", numOfTarget);
    }
    else
        printf("-1");
    

    return 0;
}


int BinarySearch(int arr[], int left, int right, int target)
{    
    int mid;

    while(left <= right)
    {
        mid = (left+right) / 2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}