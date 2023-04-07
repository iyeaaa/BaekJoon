#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

int n, c, w, tree[50];
long long ans;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> c >> w;
    F(i, 0, n) cin >> tree[i];
    sort(tree, tree + n);

    F(l, 1, tree[n - 1]+1) {
        long long money = 0;
        F(i, 0, n) {
            int k = tree[i] / l;
            int cutcnt = tree[i] % l == 0 ? tree[i] / l - 1 : tree[i] / l;
            money += max(1ll*k*l*w - c*cutcnt, 0ll);
        }
        ans = max(ans, money);
    }

    cout << ans;
}