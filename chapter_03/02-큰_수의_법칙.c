#include <stdio.h>

// 17min

void BubbleSortAsc(int arr[], int len);

int main(void)
{
	int n, m, k;
	int i, j, tmp, sum, kCnt;
	
	scanf("%d %d %d", &n, &m, &k);
	
	int arr[n];
	
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	
	
	// 배열에서 가장 큰 수를 최대한 많이 더하면 된다.
	// 이를 위해 먼저 배열을 정렬한다.(버블) 
	BubbleSortAsc(arr, n);
	

	//풀이 1 
	sum = 0;
	kCnt = 0; // 같은 인덱스의 수를 연속으로 더할 수 있는 횟수 카운팅
	

	for(i = 0; i < m; i++)
	{	
		// 가장 큰 값을 더할 수 있는 횟수를 다 쓰면
		if(kCnt == k)
		{
			sum += arr[n-2]; // 두번째로 큰 값을 더함
			kCnt = 0; // 카운팅 초기화
		}
		else
		{
			sum += arr[n-1];
			kCnt++;
		} 

	}
	
	

	
	// 풀이 2
	// {(제일 큰 수) * k + (두번째로 큰 수)}를 반복적으로 더하게 된다.
	// 이 수열은 m/(k+1)회 만큼 더할 수 있다.
	// m%(k+1)만큼은 제일 큰 수만 해당 횟수만큼 더해주면 된다.
	sum = 0;
	
	kCnt = m/(k+1); // 수열 뭉탱이를 더할 수 있는 횟수
	sum += (arr[n-1]*k + arr[n-2]) * kCnt;

	sum += (m%(k+1)) * arr[n-1];







	
	printf("%d", sum);
	
	return 0;
}

void BubbleSortAsc(int arr[], int len)
{
	int i, j;
	int tmp;
	
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < len-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}