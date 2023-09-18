#include <stdio.h>

/*
각 행에서의 최소값을 구하고, 그중에서 최대값을 구하면 된다.
16m 30s
*/

void MergeSort(int arr[], int start, int end);
void MergeTwoArea(int arr[], int start, int mid, int end);

int main(void)
{
	int n, m;
	int i, j, tmp;
	
	scanf("%d %d", &n, &m);
	int cards[n][m];
	int smallests[n]; // 각 행에서의 최소값을 저장하는 배열
	
	// 행의 최소값을 구하는 부분에서 O(n^2).
	// 행마다 병합정렬을 이용하면 O(n*mlogm)이 나오는데
	// 이게 O(n^2)보다 좋을지 잘 모르겠음.
	for(i = 0; i < n; i++)
	{
		tmp = 10001;
		
		for(j = 0; j < m; j++)
		{
			scanf("%d", &cards[n][m]);
			if(tmp > cards[n][m])
				tmp = cards[n][m];
		}
		smallests[i] = tmp;
	}
	
	MergeSort(smallests, 0, n-1);
	
	printf("%d", smallests[n-1]);
	
	return 0;
}

void MergeSort(int arr[], int start, int end)
{
	int mid = (start+end)/2;
	
	if(start < end)
	{
		MergeSort(arr, start, mid);
		MergeSort(arr, mid+1, end);
		MergeTwoArea(arr, start, mid, end);
	}
}

void MergeTwoArea(int arr[], int start, int mid, int end)
{
	int fIdx = start;
	int rIdx = mid+1;
	
	int SortArr[end];
	int sIdx = start;
	int i;
	
	while(fIdx <= mid && rIdx <= end)
	{
		if(arr[fIdx] <= arr[rIdx])
			SortArr[sIdx++] = arr[fIdx++];
		else
			SortArr[sIdx++] = arr[rIdx++];
	}
	
	if(fIdx > mid)
	{
		for(i = rIdx; i <= end; i++, sIdx++)
			SortArr[sIdx] = arr[i];
	}
	else
	{
		for(i = fIdx; i <= mid; i++, sIdx++)
			SortArr[sIdx] = arr[i];
	}
	
	for(i = start; i <= end; i++)
		arr[i] = SortArr[i];
}