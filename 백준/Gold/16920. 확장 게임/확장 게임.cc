#include <bits/stdc++.h>

#define f(i, l, r) for(int i=l;i<r;i++)
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
int n, m, p, s[10], g[1001][1001], vst[1001][1001], ans[10];
queue<pair<int, int>> q[10];

bool isEnd() {
    f(i, 1, 10) if (!q[i].empty()) return false;
    return true;
}

bool isRange(int y, int x) {
    return y >= 1 && y <= n && x >= 1 && x <= m;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    memset(vst, -1, sizeof(vst));
    cin >> n >> m >> p;
    f(i, 1, p + 1) cin >> s[i];
    f(i, 1, n + 1) {
        string x;
        cin >> x;
        f(j, 1, m + 1) {
            g[i][j] = x[j - 1];
            if (isdigit(x[j - 1])) {
                q[x[j - 1] & 15].push({i, j});
                vst[i][j] = 0;
                ans[x[j - 1] & 15]++;
            }
        }
    }

    int idx = 1;
    while (!isEnd()) {
        f(_, 0, s[idx]) {
            if (q[idx].empty())
                goto isEmpty;

            int len = q[idx].size();
            f(__, 0, len) {
                auto [y, x] = q[idx].front();
                q[idx].pop();
                f(i, 0, 4) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if (!isRange(ny, nx))
                        continue;

                    if (vst[ny][nx] != -1 || g[ny][nx] == '#')
                        continue;

                    q[idx].push({ny, nx});
                    vst[ny][nx] = vst[y][x] + 1;
                    ans[idx]++;
                }
            }
        }

        isEmpty: idx = idx == p ? 1 : idx + 1;
    }

    f(i, 1, p + 1) cout << ans[i] << ' ';
}