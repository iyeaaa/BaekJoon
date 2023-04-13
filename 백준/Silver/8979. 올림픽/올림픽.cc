#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, k, ans = 1;
    tuple<int, int, int> r[1000];
    cin >> n >> k;
    F(i, 0, n) {
        int m; cin >> m;
        cin >> get<0>(r[m]) >> get<1>(r[m]) >> get<2>(r[m]);
    }
    F(i, 0, n) ans += r[i] > r[k];
    cout << ans;
}