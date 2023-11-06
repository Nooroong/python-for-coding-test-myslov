#include <stdio.h>
#include <stdlib.h>

typedef struct _student
{
    char name[100];
    int score;
} Student;

void MergeSort(Student arr[], int left, int right);
void MergeTowArea(Student arr[], int left, int mid, int right);

int main(void)
{
    int n;
    Student * std;
    
    int i;

    scanf("%d", &n);
    std = (Student*)malloc(sizeof(Student) * n);

    for(i = 0; i < n; i++)
        scanf("%s %d", std[i].name, &(std[i].score));


    MergeSort(std, 0, n-1);

    for(i= 0; i < n; i++)
        printf("%s ", std[i].name);
    
    return 0;
}


void MergeSort(Student arr[], int left, int right)
{
    int mid;

    if(left < right)
    {
        mid = (left+right)/2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        MergeTowArea(arr, left, mid, right);
    }
}

void MergeTowArea(Student arr[], int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid+1;

    Student * sortArr;
    int sIdx = left;

    int i;

    sortArr = (Student*)malloc(sizeof(Student) * (right+1));

    while(fIdx <= mid && rIdx <= right)
    {
        if(arr[fIdx].score <= arr[rIdx].score)
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

    free(sortArr);
}
