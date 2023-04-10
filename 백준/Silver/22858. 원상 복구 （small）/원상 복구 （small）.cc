#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

const int MAX = 10001;
int n, k, p[MAX], s[MAX], d[MAX];

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> k;
    F(i, 1, n+1) cin >> s[i];
    F(i, 1, n+1) cin >> d[i];
    F(_, 0, k) {
        F(i, 1, n+1) p[d[i]] = s[i];
        F(i, 1, n+1) s[i] = p[i];
    }
    F(i, 1, n+1) cout << s[i] << ' ';
}