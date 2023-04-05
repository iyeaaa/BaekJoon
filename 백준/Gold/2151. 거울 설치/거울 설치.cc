#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef tuple<int, int, int, int> ti;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
int n, g[50][50], md[50][50][4], sy, sx;
priority_queue<ti, vector<ti>, greater<ti>> pq;

bool isRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < n;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;
    F(i, 0, n) {
        string x;
        cin >> x;
        F(j, 0, n) {
            g[i][j] = x[j];
            if (g[i][j] == '#')
                sy = i, sx = j;
        }
    }
    F(i, 0, n) F(j, 0, n) F(k, 0, 4) md[i][j][k] = 99999999;

    F(i, 0, 4) {
        md[sy][sx][i] = 0;
        int ny = sy + dy[i];
        int nx = sx + dx[i];
        if (!isRange(ny, nx)) continue;
        if (g[ny][nx] == '*') continue;
        pq.push({0, ny, nx, i});
        md[ny][nx][i] = 0;
    }

    while (!pq.empty()) {
        auto [dist, y, x, dir] = pq.top();
        pq.pop();
        if (dist > md[y][x][dir]) continue;
        if (g[y][x] == '#') {
            cout << dist;
            exit(0);
        }
        if (g[y][x] == '!') {
            int dir1 = (dir + 3) % 4;
            int dir2 = (dir + 1) % 4;
            if (dist + 1 < md[y][x][dir1]) {
                pq.push({dist + 1, y, x, dir1});
                md[y][x][dir1] = dist + 1;
            }
            if (dist + 1 < md[y][x][dir2]) {
                pq.push({dist + 1, y, x, dir2});
                md[y][x][dir2] = dist + 1;
            }
        }
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (!isRange(ny, nx)) continue;
        if (g[ny][nx] == '*') continue;
        if (dist >= md[ny][nx][dir]) continue;
        pq.push({dist, ny, nx, dir});
        md[ny][nx][dir] = dist;
    }
}