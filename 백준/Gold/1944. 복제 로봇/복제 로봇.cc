#include <bits/stdc++.h>

#define FIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define FOR(i, l, r) for (int i = l; i < r; i++)
using namespace std;
typedef pair<int, int> pii;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
int n, m, g[51][51], sy, sx, ans;

// O(N*N)
tuple<int,int,int> mnDist(queue<pii> q) {
    int v[51][51];
    memset(v, -1, sizeof(v));
    FOR(i, 0, q.size())
        v[q.front().first][q.front().second] = 0,
        q.push(q.front()),
        q.pop();

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        FOR(i, 0, 4) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (v[ny][nx] != -1 || g[ny][nx] == '1')
                continue;

            if (g[ny][nx] == 'K')
                return {v[y][x] + 1, ny, nx};

            q.emplace(ny, nx);
            v[ny][nx] = v[y][x] + 1;
        }
    }

    return {-1, 0, 0}; // 불가능
}

int main() {
    FIO
    cin >> n >> m;
    FOR(i, 0, n) {
        string x;
        cin >> x;
        FOR(j, 0, n) {
            g[i][j] = x[j];
            if (x[j] == 'S') sy = i, sx = j;
        }
    }

    queue<pii> q;
    q.emplace(sy, sx);
    FOR(i, 0, m) {
        auto [plus, ny, nx] = mnDist(q);
        if (plus == -1) {
            ans = -1;
            break;
        }

        ans += plus;
        q.emplace(ny, nx);
    }

    cout << ans;
}