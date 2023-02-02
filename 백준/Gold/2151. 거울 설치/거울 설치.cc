
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int> tii;
typedef tuple<ll, ll, ll> tll;
typedef vector<int> vi;

string input;
int n, g[51][51], fy, fx, fd, mindist[51][51][4];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
priority_queue<tii, vector<tii>, greater<tii>> pq;

bool isRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < n;
}

void findStt() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (g[y][x] == '#') {
                mindist[y][x][0] = 0;
                mindist[y][x][1] = 0;
                mindist[y][x][2] = 0;
                mindist[y][x][3] = 0;
                for (int d = 0; d < 4; d++) {
                    int ny = y+dy[d], nx = x+dx[d];
                    if (!isRange(ny, nx)) continue;
                    if (g[ny][nx] == '*') continue;
                    mindist[ny][nx][d] = 0;
                    pq.push({0, ny, nx, d});
                }
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < n; j++) {
            g[i][j] = input[j];
        }
    }

    fill(&mindist[0][0][0], &mindist[50][50][4], 99999999);
    findStt();

    while (!pq.empty()) {
        auto [dist, y, x, d] = pq.top(); pq.pop();
        if (dist > mindist[y][x][d]) continue;

        if (g[y][x] == '#') {
            cout << mindist[y][x][d];
            exit(0);
        }

        int ny = y+dy[d], nx = x+dx[d], nd = d;
        if (isRange(ny,nx) && dist < mindist[ny][nx][nd] && g[ny][nx] != '*') {
            mindist[ny][nx][nd] = dist;
            pq.push({dist, ny, nx, nd});

        }

        if (g[y][x] == '.') continue;

        for (int i = 0; i < 4; i++) if (d != i) {
            int ny = y+dy[i], nx = x+dx[i], nd = i;
            if (!isRange(ny, nx)) continue;
            if (g[ny][nx] == '*') continue;
            if (dist+1 >= mindist[ny][nx][nd]) continue;
            mindist[ny][nx][nd] = dist+1;
            pq.push({dist+1, ny, nx, nd});
        }
    }
}
