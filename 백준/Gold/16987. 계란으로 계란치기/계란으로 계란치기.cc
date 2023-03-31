#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
using namespace std;

int n, ans;
pair<int, int> eggs[8];

bool allBroken(int idx) {
    F(i, 0, n) if (idx != i && eggs[i].first > 0) return false;
    return true;
}

void f(int idx, int sum) {
    if (idx >= n) {
        ans = max(ans, sum);
        return;
    }

    if (eggs[idx].first <= 0 || allBroken(idx)) {
        f(idx + 1, sum);
        return;
    }

    F(i, 0, n) if (idx != i && eggs[i].first > 0) {
        auto& [s1, w1] = eggs[idx];
        auto& [s2, w2] = eggs[i];

        s1 -= w2;
        s2 -= w1;

        f(idx+1, sum + (s1 <= 0) + (s2 <= 0));

        s1 += w2;
        s2 += w1;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;
    F(i, 0, n) cin >> eggs[i].first >> eggs[i].second;
    f(0, 0);

    cout << ans;
}
