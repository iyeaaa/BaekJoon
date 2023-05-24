#include <bits/stdc++.h>

#define FIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define FOR(i, l, r) for (int i = l; i < r; i++)
using namespace std;
typedef pair<int, int> pii;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
int n, m, ans;
vector<pii> g[101][101];
bool on[101][101], v[101][101];

void f() {
    queue<pii> q;

    ans++;
    on[1][1] = true;
    v[1][1] = true;
    q.emplace(1, 1);

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (auto [ly, lx]: g[y][x]) if (!on[ly][lx]) {
            on[ly][lx] = true;
            ans++;
            FOR(i, 0, 4) {
                int ny = ly + dy[i];
                int nx = lx + dx[i];
                if (v[ny][nx]) {
                    q.emplace(ly, lx);
                    v[ly][lx] = true;
                    break;
                }
            }
        }

        FOR(i, 0, 4) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 1 || ny > n || nx < 1 || nx > n || v[ny][nx] || !on[ny][nx])
                continue;

            v[ny][nx] = true;
            q.emplace(ny, nx);
        }
    }
}

int main() {
    FIO
    cin >> n >> m;
    FOR(i, 0, m) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        g[x][y].emplace_back(a, b);
    }

    f();
    cout << ans;
}