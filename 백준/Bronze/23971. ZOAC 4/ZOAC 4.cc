#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int h, w, n, m;
    cin >> h >> w >> n >> m;
    cout << ((h+n)/(n+1)) * ((w+m)/(m+1));
}