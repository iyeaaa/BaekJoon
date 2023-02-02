
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

priority_queue<tii, vector<tii>, greater<tii>> pq;
int n, g[51][51], mindist[51][51];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
string x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        for (int j = 1; j <= n; j++)
            g[i][j] = x[j-1] - 48;
    }

    fill(&mindist[0][0], &mindist[50][51], 99999999);
    mindist[1][1] = 0;
    pq.push({0, 1, 1});

    while (!pq.empty()) {
        auto [dist, y, x] = pq.top(); pq.pop();
        if (dist > mindist[y][x]) continue;
        if (y == n && x == n) break;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 1 || ny > n || nx < 1 || nx > n) continue;
            if (dist + (1 - g[ny][nx]) >= mindist[ny][nx]) continue;
            mindist[ny][nx] = dist + (1 - g[ny][nx]);
            pq.push({dist +(1- g[ny][nx]), ny, nx});
        }
    }

    cout << mindist[n][n];
}
