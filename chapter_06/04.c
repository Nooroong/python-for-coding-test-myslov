#include <stdio.h>
#include <stdlib.h>

/*
23m 55s
배열 A의 가장 작은 수와 배열 B의 가장 큰 수를 비교하여 교환한다.
이 과정을 반복하면 최대합을 가지는 배열 A를 만들 수 있다.
*/

void MergeSort(int arr[], int left, int right);
void MergeTwoArea(int arr[], int left, int mid, int right);

int main(void)
{
    int n, k;
    int * arr1, * arr2;
    int maxSum;
    int idx1, idx2;
    int i;

    scanf("%d %d", &n, &k);

    arr1 = (int*)malloc(sizeof(int)*n);
    arr2 = (int*)malloc(sizeof(int)*n);

    for(i = 0; i < n; i++) scanf("%d", &arr1[i]);
    for(i = 0; i < n; i++) scanf("%d", &arr2[i]);

    MergeSort(arr1, 0, n-1);
    MergeSort(arr2, 0, n-1);
    
    for(idx1 = 0, idx2 = n-1; k > 0; )
    {
        if(arr1[idx1] < arr2[idx2])
        {
            int tmp = arr1[idx1];
            arr1[idx1] = arr2[idx2];
            arr2[idx2] = tmp;
            k--, idx1++, idx2--;
        }
        else
            break;
    }

    for(i = 0; i < n; i++) maxSum += arr1[i];
    printf("%d", maxSum);

    return 0;
}

void MergeSort(int arr[], int left, int right)
{
    int mid;

    if(left < right)
    {
        mid = (left+right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        MergeTwoArea(arr, left, mid, right);
    }
}

void MergeTwoArea(int arr[], int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid + 1;
    
    int * sortArr = (int*)malloc(sizeof(int) * right);
    int sIdx = left;

    int i;

    while(fIdx <= mid && rIdx <= right)
    {
        if(arr[fIdx] <= arr[rIdx])
            sortArr[sIdx++] = arr[fIdx++];
        else
            sortArr[sIdx++] = arr[rIdx++];
    }

    if(fIdx > mid)
    {
        while(rIdx <= right)
            sortArr[sIdx++] = arr[rIdx++];
    }
    else
    {
        while(fIdx <= mid)
            sortArr[sIdx++] = arr[fIdx++];
    }

    for(i = left; i <= right; i++)
        arr[i] = sortArr[i];
}