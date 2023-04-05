#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

int n, m, mxcnt, ans = 999999;
long long g[10];

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    F(i, 0, n) {
        long long info = 0;
        string x;
        cin >> x;
        cin >> x;
        F(j, 0, m) {
            info += x[j] == 'Y';
            info <<= 1;
        }
        g[i] = info >> 1;
    }

    F(i, 1, (1 << n)) {
        long long info = 0;
        int guitarcnt = 0;
        int songcnt = 0;
        F(j, 0, n) if (i & (1 << j)) {
            guitarcnt++;
            info |= g[j];
        }
        F(j, 0, m) if (info & (1ll << j)) songcnt++;
        if (songcnt >= mxcnt)
            ans = songcnt > mxcnt ? guitarcnt : min(ans, guitarcnt),
            mxcnt = songcnt;
    }

    cout << (mxcnt == 0 ? -1 : ans);
}

