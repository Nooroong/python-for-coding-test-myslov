#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

/*
배열 전체에서 DFS로 탐색이 가능한 개수를 구하면 된다.

4 5
00110
00011
11111
00000

15 14
00000111100000
11111101111110
11011101101110
11011101100000
11011111111111
11011111111100
11000000011111
01111111111111
00000000011111
01111111111000
00011111111000
00000001111000
11111111110011
11100011111111
11100011111111
*/

int DFS(int ** graph, int startRow, int startCol, int rowSize, int colSize);

int main(void)
{
    int n, m;
    int ** ice; // 얼음 틀 정보
    int cnt; // 얼음 덩어리의 수
    int i, j;

    scanf("%d %d", &n, &m); // 얼음 틀 크기 입력

    // 얼음 틀 배열 할당
    ice = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++)
        ice[i] = (int*)malloc(sizeof(int) * m);
    

    // 얼음 틀 정보 입력
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            scanf("%1d", &ice[i][j]);
    }

    // 배열 전체를 돌면서 탐색이 가능한 수를 구함
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            if(DFS(ice, i, j, n, m))
                cnt++;
    }

    printf("%d", cnt); // 얼음 덩어리의 수 출력

    return 0;
}


int DFS(int ** graph, int startRow, int startCol, int rowSize, int colSize)
{
    // 범위를 벗어난 경우 탐색 종료.
    if(startRow < 0 || startRow >= rowSize || startCol < 0 || startCol >= colSize)
        return FALSE;
    
    // 현재 노드에 아직 방문하지 않았다면,
    if(graph[startRow][startCol] == 0)
    {
        graph[startRow][startCol] = 1; // 방문 처리

        // 현재 노드의 상, 하, 좌, 우 노드에 대해 DFS.
        DFS(graph, startRow-1, startCol, rowSize, colSize);
        DFS(graph, startRow+1, startCol, rowSize, colSize);
        DFS(graph, startRow, startCol-1, rowSize, colSize);
        DFS(graph, startRow, startCol+1, rowSize, colSize);

        return TRUE;
    }

    return FALSE;
}