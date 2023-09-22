#include <stdio.h>

int main(void)
{
    int n, m; // 맵의 세로, 가로 크기
    int a, b, d; // 시작 좌표 (a, b), 캐릭터가 바라보는 방향 d
    int turnTime; // 전진하지 못하고 돌기만 한 수
    int visit; // 캐릭터가 방문한 칸의 수
    int i, j;

    scanf("%d %d", &n, &m);
    int map[n][m]; // 0은 육지, 1은 바다, -1은 이미 가본 곳.

    scanf("%d %d %d", &a, &b, &d);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            scanf("%d", &map[i][j]);
    }




    map[a][b] = -1;
    turnTime = 0;
    visit = 1; // 시작 좌표도 포함

    while(1)
    {
        // 일단 현 위치에서 반시계 방향으로 90도 회전하여.
        d = (d-1)<0 ? 3 : d-1; // 회전
        
        // 그쪽에 가보지 않은 칸이 있다면 한 칸 전진.
        switch(d)
        {
            case 0: // 북
                if(map[a-1][b] == 0)
                {
                    map[--a][b] = -1;
                    turnTime = 0;
                    visit++;
                    continue;
                }
                break;
            case 1: // 동
                if(map[a][b+1] == 0)
                {
                    map[a][++b] = -1;
                    turnTime = 0;
                    visit++;
                    continue;
                }
                break;
            case 2: // 남
                if(map[a+1][b] == 0)
                {
                    map[++a][b] = -1;
                    turnTime = 0;
                    visit++;
                    continue;
                }
            case 3: // 서
                if(map[a][b-1] == 0)
                {
                    map[a][--b] = -1;
                    turnTime = 0;
                    visit++;
                    continue;
                }
        }
        
        turnTime++; // 전진하지 못 하고 회전만 함.
        
        // 네 방향 모두 갈 수 없는 칸이라면 방향을 유지한 채 한 칸 뒤로.
        if(turnTime >= 4)
        {
            switch(d)
            {
                case 0: // 북
                    a++;
                    break;
                case 1: // 동
                    b--;
                    break;
                case 2: // 남
                    a--;
                    break;
                case 3: // 서
                    b++;
                    break;
            }

            // 근데 그 칸이 바다라면 움직임을 멈춤.
            if(map[a][b] == 1)
                break;
            else // 그 칸이 육지인 경우.
                turnTime = 0; // 칸을 이동했으므로 회전 횟수 초기화.
        }
    }

    printf("%d", visit);
    
    return 0;
}