#include <bits/stdc++.h>

#define FOR(i, l, r) for (int i = l; i < r; i++)
using namespace std;

bool isUsed[7][7];
int g[8][7], ans;
bool v[8][7];

void f(int y, int x) {
    if (x == 7) {
        f(y+1, 0);
        return;
    }
    if (y == 7 && x == 6) {
        if (v[y][x]) ans++;
        return;
    }
    if (v[y][x]) {
        f(y, x+1);
        return;
    }

    if (y < 7 && !v[y+1][x]) {
        int lo = min(g[y][x], g[y+1][x]);
        int hi = max(g[y][x], g[y+1][x]);

        if (!isUsed[lo][hi]) {
            isUsed[lo][hi] = true;
            v[y+1][x] = true;
            f(y, x+1);
            isUsed[lo][hi] = false;
            v[y+1][x] = false;
        }
    }
    if (x < 6 && !v[y][x+1]) {
        int lo = min(g[y][x], g[y][x+1]);
        int hi = max(g[y][x], g[y][x+1]);

        if (!isUsed[lo][hi]) {
            isUsed[lo][hi] = true;
            v[y][x+1] = true;
            f(y, x+1);
            isUsed[lo][hi] = false;
            v[y][x+1] = false;
        }
    }
}

int main() {
//    freopen("input.txt", "r", stdin);

    FOR(i, 0, 8) {
        string s;
        cin >> s;
        FOR(j, 0, 7) g[i][j] = s[j];
    }

    f(0, 0);
    cout << ans;
}