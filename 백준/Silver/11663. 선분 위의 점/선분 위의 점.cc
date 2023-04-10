#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

int n, m, l[100'001];

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    
    cin >> n >> m;
    F(i, 0, n) cin >> l[i];
    sort(l, l+n);

    F(i, 0, m) {
        int lo, hi;
        cin >> lo >> hi;

        int loidx = lower_bound(l, l+n, lo) - l;
        int hiidx = upper_bound(l, l+n, hi) - l;

        cout << (hiidx - loidx) << '\n';
    }
}