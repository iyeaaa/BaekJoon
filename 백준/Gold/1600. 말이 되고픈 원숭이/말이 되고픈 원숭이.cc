#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int K;
// bY
int W;
// bX
int H;
int board[202][202] = {};
int visited[202][202][32] = {};
int jumpDx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int jumpDy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool OOB(int x, int y)
{
    return x < 0 || y < 0 || x >= H || y >= W;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<tuple<int, int, int>> q;
    cin >> K >> W >> H;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> board[i][j];

    q.push({0, 0, 0});
    while (!q.empty())
    {
        auto [x, y, jump] = q.front();
        q.pop();
        if (x == H - 1 && y == W - 1)
        {
            cout << visited[x][y][jump];
            return 0;
        }
        if (jump < K)
        {
            for (int dir = 0; dir < 8; dir++)
            {
                int nx = jumpDx[dir] + x;
                int ny = jumpDy[dir] + y;
                if (OOB(nx, ny))
                    continue;
                // 방문했던 곳 || 가는 곳이 장애물일 때
                if (visited[nx][ny][jump + 1] || board[nx][ny])
                    continue;
                q.push({nx, ny, jump + 1});
                visited[nx][ny][jump + 1] = visited[x][y][jump] + 1;
            }
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = dx[dir] + x;
            int ny = dy[dir] + y;
            if (OOB(nx, ny))
                continue;
            // 방문했던 곳일 때 || 가는 곳이 장애물 일 때
            if (visited[nx][ny][jump] || board[nx][ny])
                continue;
            q.push({nx, ny, jump});
            visited[nx][ny][jump] = visited[x][y][jump] + 1;
        }
    }
    cout << -1;
}
