#include <bits/stdc++.h>

#define FOR(i, l, r) for (int i = l; i < r; i++)
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
int n, m, a, b, k, obs[501][501], v[501][501];
int sy, sx, ey, ex;
queue<pair<int, int>> q;

int main() {
    fill(&v[0][0], &v[500][501], -1);
    cin >> n >> m >> a >> b >> k;
    FOR(i, 0, k) {
        int y, x;
        cin >> y >> x;
        obs[y][x] = true;
    }
    cin >> sy >> sx >> ey >> ex;
    q.emplace(sy, sx);
    v[sy][sx] = 0;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        if (y == ey && x == ex) {
            cout << v[y][x];
            exit(0);
        }
        FOR(i, 0, 4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 1 || ny > n-(a-1) || nx < 1 || nx > m-(b-1)) continue;
            if (~v[ny][nx]) continue;
            FOR(j, 0, a) FOR(l, 0, b) if (obs[ny+j][nx+l]) goto first;
            q.emplace(ny, nx);
            v[ny][nx] = v[y][x] + 1;
            first:;
        }
    }
    cout << -1;
}