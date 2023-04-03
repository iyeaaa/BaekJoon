#include <bits/stdc++.h>

#define fb(i, l, r) for (int i=l; i<r; i++)
#define ft(i, l, r) for (int i=l; i<=r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

int n, m, a[101], dp[101][51], psum[101];

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    fill(&dp[0][0], &dp[99][51], -99999999);
    ft(i, 1, n) cin >> a[i], psum[i] = psum[i - 1] + a[i];
    ft(i, 0, n) dp[i][0] = 0;
    dp[1][1] = a[1];
    dp[2][1] = max(a[1] + a[2], max(a[1], a[2]));

    ft(i, 3, n) ft(j, 1, m) {
        dp[i][j] = dp[i-1][j];
        ft(k, 0, i-2)
            dp[i][j] = max(dp[i][j], dp[k][j-1] + psum[i] - psum[k+1]);
    }

    cout << dp[n][m];
}