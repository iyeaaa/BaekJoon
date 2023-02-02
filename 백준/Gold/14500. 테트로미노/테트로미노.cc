
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, G[501][501], V[501][501], ans;
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

void dfs(int y, int x, int cnt, int sum) {
    if (cnt == 4) {
        ans = max(ans, sum+G[y][x]);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y+dy[i], nx = x+dx[i];
        if (V[ny][nx]) continue;
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        V[ny][nx] = true;
        dfs(ny, nx, cnt + 1, sum + G[y][x]);
        V[ny][nx] = false;
    }
}

void solve() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            V[i][j] = true;
            dfs(i, j, 1, 0);
            V[i][j] = false;
            if (j+2 < M) {
                int sum = 0;
                for (int k = j; k < j+3; k++) sum += G[i][k];
                if (i-1 >= 0)
                    ans = max(ans, sum+G[i-1][j+1]);
                if (i+1 < N)
                    ans = max(ans, sum+G[i+1][j+1]);
            }
            if (i+2 < N) {
                int sum = 0;
                for (int k = i; k < i+3; k++) sum += G[k][j];
                if (j-1 >= 0)
                    ans = max(ans, sum + G[i+1][j-1]);
                if (j+1 < M)
                    ans = max(ans, sum + G[i+1][j+1]);
            }
        }
    cout << ans;
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> G[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    input(), solve();
}
