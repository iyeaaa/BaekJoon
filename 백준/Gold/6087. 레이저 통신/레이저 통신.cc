
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int> tii;

priority_queue<tii, vector<tii>, greater<tii>> pq;
int w, h, mindist[101][101][4], g[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
string x;

bool isRange(int y, int x) {
    return y >= 0 && y < h && x >= 0 && x < w;
}

pii findStart() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (g[i][j] == 'C') {
                return {i, j};
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        cin >> x;
        for (int j = 0; j < w; j++)
            g[i][j] = x[j];
    }
    fill(&mindist[0][0][0], &mindist[100][100][4], 99999999);

    pii s = findStart();
    mindist[s.first][s.second][0] = 0;
    mindist[s.first][s.second][1] = 0;
    mindist[s.first][s.second][2] = 0;
    mindist[s.first][s.second][3] = 0;

    for (int i = 0; i < 4; i++) {
        int ny = s.first + dy[i], nx = s.second + dx[i];
        if (!isRange(ny, nx)) continue;
        if (g[ny][nx] == '*') continue;
        pq.push({0, ny, nx, i});
        mindist[ny][nx][i] = 0;
    }


    while (!pq.empty()) {
        auto [dist, y, x, dir] = pq.top(); pq.pop();
        if (dist > mindist[y][x][dir]) continue;
        for (int i = 0; i < 4; i++) {
            int ny = y+dy[i], nx = x+dx[i];
            if (!isRange(ny, nx)) continue;
            if (g[ny][nx] == '*') continue;
            if (dir == i) {
                if (dist >= mindist[ny][nx][i]) continue;
                pq.push({dist, ny, nx, i});
                mindist[ny][nx][i] = dist;
            } else {
                if (dist+1 >= mindist[ny][nx][i]) continue;
                pq.push({dist+1, ny, nx, i});
                mindist[ny][nx][i] = dist+1;
            }
            if (g[ny][nx] == 'C') {
                cout << mindist[ny][nx][i];
                exit(0);
            }
        }
    }
}
