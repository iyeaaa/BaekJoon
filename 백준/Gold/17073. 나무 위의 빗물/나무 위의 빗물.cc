#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

int n, w, a[500'001], leafcnt;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> w;
    F(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        a[u]++, a[v]++;
    }
    F(i, 2, n+1) leafcnt += a[i] == 1;

    cout.precision(4);
    cout << fixed << (1.0 * w / leafcnt) << endl;
}