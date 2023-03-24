#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

typedef vector<int> vi;

const int MAXN = 1001;
int n, m, k, g[MAXN][MAXN], dy[] = {-1, 0, 1, 0}, dx[] = {0, -1, 0, 1};

bool OOB(int y, int x) {
    return y < 1 || y > n || x < 1 || x > m;
}

int f() {
    queue<tuple<int, int, int, int>> q;
    int vst[MAXN][MAXN][11][2];
    memset(vst, -1, sizeof(vst));

    q.push({1, 1, 0, 1});
    vst[1][1][0][1] = 1;

    while (!q.empty()) {
        auto [y, x, c, light] = q.front();
        q.pop();

        if (y == n && x == m) {
            return vst[y][x][c][light];
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (OOB(ny, nx)) {
                continue;
            }

            if (g[ny][nx] == 1 && (c >= k || !light)) {
                continue;
            }

            int nc = c + (g[ny][nx] == 1);
            int nlight = !light;

            if (vst[ny][nx][nc][nlight] != -1) {
                continue;
            }

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
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        string x;
        cin >> x;
        for (int j = 1; j <= m; j++) {
            g[i][j] = x[j-1] & 15;
        }
    }

    cout << f() << '\n';
    return 0;
}
