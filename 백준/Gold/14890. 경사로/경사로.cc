#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

int n, l, g[100][100], ans;

bool good(const vector<int> brid) {
    bool put[100] = {0, };
    F(i, 1, n) {
        if (abs(brid[i-1] - brid[i]) > 1)
            return false;
        if (brid[i-1] < brid[i]) {
            if (i < l) return false;
            F(j, i-l, i) {
                if (brid[j] != brid[i - 1] || put[j])
                    return false;
                put[j] = true;
            }
        }
        else if (brid[i-1] > brid[i]) {
            if (n-i+1 < l) return false;
            F(j, i, i+l) {
                if (brid[j] != brid[i])
                    return false;
                put[j] = true;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> l;
    F(i, 0, n) F(j, 0, n) cin >> g[i][j];

    F(i, 0, n) {
        vector<int> brid1;
        vector<int> brid2;
        F(j, 0, n)
            brid1.push_back(g[i][j]),
            brid2.push_back(g[j][i]);
        ans += good(brid1) + good(brid2);
    }

    cout << ans;
}