#include <bits/stdc++.h>

#define f(i, l, r) for(int i=l;i<r;i++)
using namespace std;

int n;
double a[10001], dp[10001], ans;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;
    f(i, 0, n) cin >> a[i];

    dp[0] = a[0], ans = a[0];
    f(i, 1, n) dp[i] = max(a[i], dp[i - 1] * a[i]), ans = max(ans, dp[i]);

    printf("%.3f", ans);
}
