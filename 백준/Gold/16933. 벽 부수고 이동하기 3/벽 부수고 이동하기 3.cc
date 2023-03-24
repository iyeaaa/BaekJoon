#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int n, m, k, g[1001][1001];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

bool OOB(int y, int x) {
    return y < 1 || y > n || x < 1 || x > m;
}

int f() {
    queue<tuple<int, int, int, int>> q;
    int vst[n+1][m+1][k+1][2];

    q.push({1, 1, 0, 1});
    fill(&vst[0][0][0][0], &vst[n][m][k][2], -1);
    vst[1][1][0][1] = 1;

    while (!q.empty()) {
        auto [y, x, c, light] = q.front();
        if (y == n && x == m) return vst[y][x][c][light];
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (OOB(ny, nx)) continue;
            if (g[ny][nx] == 1 && (c >= k || !light)) continue;

            int nc = c + (g[ny][nx] == 1);
            int nlight = !light;

            if (vst[ny][nx][nc][nlight] != -1) continue;

            q.push({ny, nx, nc, nlight});
            vst[ny][nx][nc][nlight] = vst[y][x][c][light] + 1;
        }
        if (vst[y][x][c][!light] == -1) {
            q.push({y, x, c, !light});
            vst[y][x][c][!light] = vst[y][x][c][light] + 1;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        string x;
        cin >> x;
        for (int j = 1; j <= m; j++)
            g[i][j] = x[j-1] & 15;
    }

    cout << f();
}