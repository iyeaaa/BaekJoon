#include <bits/stdc++.h>

#define fr(i, l, r) for(int i=l;i<r;i++)
using namespace std;

int r, c, k, ans, g[5][5], v[5][5];
vector<string> stk;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

void f(int y, int x, int d, string s) {
    if (d == k && y == 0 && x == c - 1) ans++, stk.push_back(s);
    if (d == k) return;
    fr (i, 0, 4) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        if (v[ny][nx] || g[ny][nx] == 'T') continue;
        v[ny][nx] = true;
        f(ny, nx, d + 1, s+to_string(ny) + to_string(nx) + " ");
        v[ny][nx] = false;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> r >> c >> k;
    fr(i, 0, r) {
        string x;
        cin >> x;
        fr(j, 0, c)
            g[i][j] = x[j];
    }


    v[r-1][0] = true;
    f(r - 1, 0, 1, to_string(r-1) + to_string(0) + " ");
    cout << ans;
}
