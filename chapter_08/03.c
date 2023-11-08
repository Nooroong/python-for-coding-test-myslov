#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (a)>(b)?(a):(b)

/*
40m 00s

bottom-up 방식을 이용.
해당 칸에 왔을 때 얻을 수 있는 최대 식량 수를 DP 테이블에 저장한다.
몇칸을 건너뛰어야 할지 고민될 수 있다.
2칸, 3칸, 4칸, 5칸 6칸…
여기서 4칸은 2칸+2칸으로 표현할 수 있고 5칸은 3칸+3칸으로 표현할 수 있다.
중간에 엄청 큰 수가 있어 거기로 점프한다고 할 때,
중간에 거칠 수 있는 칸은 다 거치는 편이 더 많은 식량을 약탈할 수 있다.
이를 좀 더 일반화하면 짝수칸은 2칸*n으로, 홀수칸은 2칸*(n-1) + 3칸으로 표현할 수 있다.
그러므로 2칸을 이동해야할지, 3칸을 이동해야할지만 고민하면 될 것 같다.
*/

int d[101] = {0}; // DP table

void MergeSortASC(int arr[], int left, int right);
void MergeTwoArea(int arr[], int left, int mid, int right);

int main(void)
{
    int n;
    int * food;
    int i;

    scanf("%d", &n);
    food = (int*)malloc(sizeof(int) * (n+1));
    for(i = 1; i <= n; i++) scanf("%d", &food[i]);

    // 첫번째 칸, 두번째 칸까지 왔을 때 최대로 약탈할 수 있는 식량의 양은
    // 그 칸의 값 만큼이다. 둘은 첫 시작점이 될 수 밖에 없기 때문이다.
    // 그래서 이 값은 DP 테이블에 그대로 넣어준다.
    d[1] = food[1];
    d[2] = food[2];
    d[3] = food[1] + food[3]; // 얘도 자명함(?)

    for(i = 4; i <= n; i++)
        d[i] = MAX((food[i] + d[i-2]), (food[i] + d[i-3]));

    
    // MergeSortASC(d, 0, n);

    printf("%d", d[n]); // d[n]이 항상 최댓값이라고 할 수 있는지 모르겠음.


    return 0;
}

void MergeSortASC(int arr[], int left, int right)
{
    int mid;

    if(left < right)
    {
        mid = (left+right)/2;
        MergeSortASC(arr, left, mid);
        MergeSortASC(arr, mid+1, right);
        MergeTwoArea(arr, left, mid, right);
    }
}

void MergeTwoArea(int arr[], int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid+1;
    int sIdx = left;

    int i;

    int sortArr[(right+1)];


    while(fIdx <= mid && rIdx <= right)
    {
        if(arr[fIdx] < arr[rIdx])
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