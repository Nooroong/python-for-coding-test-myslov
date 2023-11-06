#include <stdio.h>
#include <stdlib.h>

// start: arr의 시작 인덱스, end: arr의 마지막 인덱스
void MergeSortDESC(int arr[], int start, int end);

void MergeTowArea(int arr[], int start, int mid, int end);

int main(void)
{
    int n;
    int * arr;
    int i;

    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int) * n);

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    MergeSortDESC(arr, 0, n-1);
    
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

void MergeSortDESC(int arr[], int start, int end)
{
    int mid = (start + end) / 2;
    
    if(start < end)
    {
        MergeSortDESC(arr, start, mid);
        MergeSortDESC(arr, mid + 1, end);
        MergeTowArea(arr, start, mid, end);
    }
}

void MergeTowArea(int arr[], int start, int mid, int end)
{
    int fIdx = start;
    int rIdx = mid + 1;

    int * sortArr;
    int sIdx = start;

    int i;

    sortArr = (int*)malloc(sizeof(int) * (end+1));

    while(fIdx <= mid && rIdx <= end)
    {
        if(arr[fIdx] >= arr[rIdx])
            sortArr[sIdx++] = arr[fIdx++];
        else
            sortArr[sIdx++] = arr[rIdx++];
    }

    if(fIdx > mid)
    {   
        while(rIdx <= end)
            sortArr[sIdx++] = arr[rIdx++];
    }
    else
    {
        while(fIdx <= mid)
            sortArr[sIdx++] = arr[fIdx++];
    }


    for(i = start; i <= end; i++)
        arr[i] = sortArr[i];

    free(sortArr);
}