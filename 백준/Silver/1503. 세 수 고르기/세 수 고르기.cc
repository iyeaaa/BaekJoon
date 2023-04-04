#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

int n, m, ans = 2'100'000'000, s[1002];

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    F(i, 0, m) { int x; cin >> x; s[x] = true; }

    F(i, 1, 1002) if (!s[i])
        F(j, 1, 1002) if (!s[j])
            F(k, 1, 1002) if (!s[k])
                ans = min(ans, abs(n - i*j*k));

    cout << ans;
}

