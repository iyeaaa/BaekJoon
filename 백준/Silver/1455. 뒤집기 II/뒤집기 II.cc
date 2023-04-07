#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

int n, m, g[100][100], ans;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    F(i, 0, n) {
        string x;
        cin >> x;
        F(j, 0, m) g[i][j] = x[j] & 15;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (g[i][j] == 1) {
                ans++;
                for (int k = 0; k <= i; k++)
                    for (int l = 0; l <= j; l++)
                        g[k][l] = !g[k][l];
            }
        }
    }

    cout << ans;
}