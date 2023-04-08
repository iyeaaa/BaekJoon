#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

int dy[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dx[] = {0, -1, 0, 1, -1, 1, -1, 1};
int n, g[10][10], allOpen, open[10][10];

bool isRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < n;
}

int main() {
    cin >> n;
    F(i, 0, n) {
        string x;
        cin >> x;
        F(j, 0, n) g[i][j] = x[j];
    }

    F(i, 0, n) {
        string x;
        cin >> x;
        F(j, 0, n) {
            if (g[i][j] == '*' && x[j] == 'x')
                allOpen = true;
            open[i][j] = x[j] == 'x';
        }
    }

    F(i, 0, n) F(j, 0, n) {
        if (g[i][j] == '.' && open[i][j]) {
            int cnt = 0;
            F(k, 0, 8) {
                int ni = i + dy[k];
                int nj = j + dx[k];
                if (!isRange(ni, nj)) continue;
                cnt += g[ni][nj] == '*';
            }
            cout << cnt;
        } else if (g[i][j] == '*' && allOpen) {
            cout << '*';
        } else {
            cout << '.';
        }
        if (j == n-1) cout << '\n';
    }
}