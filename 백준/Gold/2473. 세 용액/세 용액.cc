#include <bits/stdc++.h>

#define fr(i, l, r) for(int i=l;i<r;i++)
using namespace std;
typedef long long ll;

int n;
ll a[5001], ans = 4'000'000'000;
vector<ll> ansList;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;
    fr(i, 0, n) cin >> a[i];
    sort(a, a + n);

    fr(i, 0, n) {
        fr(j, i + 1, n) {
            ll lo = a[i];
            ll hi = a[j];
            int idx = lower_bound(a + j + 1, a + n, -lo - hi) - a;
            if (idx < n && abs(lo + hi + a[idx]) < abs(ans)) {
                ans = lo + hi + a[idx];
                ansList = {lo, hi, a[idx]};
            }
            if (idx > j + 1 && abs(lo + hi + a[idx - 1]) < abs(ans)) {
                ans = lo + hi + a[idx - 1];
                ansList = {lo, hi, a[idx - 1]};
            }
        }
    }

    cout << ansList[0] << ' ' << ansList[1] << ' ' << ansList[2];
}
