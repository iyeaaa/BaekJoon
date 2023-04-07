#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

int n, m, l[2001];
vector<int> s[2001];

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    F(i, 1, n+1) {
        int x, y;
        cin >> x;
        F(j, 0, x) cin >> y, l[y]++, s[i].push_back(y);
    }

    F(i, 1, n+1) {
        for (int v: s[i])
            l[v]--;
        bool can = true;
        F(j, 1, m+1) {
            can = l[j] > 0;
            if (!can) break;
        }
        if (can) {
            cout << 1;
            exit(0);
        }
        for (int v: s[i])
            l[v]++;
    }

    cout << 0;
}