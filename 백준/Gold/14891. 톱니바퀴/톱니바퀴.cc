#include <bits/stdc++.h>

using namespace std;

int k, ans;
vector<bool> t[4];

void rotate(int idx, int clock, bool lf, bool ryt) {
    int lo = t[idx][6];
    int hi = t[idx][2];

    if (clock) {
        t[idx].insert(t[idx].begin(), t[idx].back());
        t[idx].pop_back();
    } else {
        t[idx].push_back(t[idx].front());
        t[idx].erase(t[idx].begin());
    }

    if (idx > 0 && lf && lo != t[idx - 1][2])
        rotate(idx - 1, !clock, true, false);

    if (idx < 3 && ryt && hi != t[idx + 1][6])
        rotate(idx + 1, !clock, false, true);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    for (int i = 0; i < 4; i++) {
        string x;
        cin >> x;
        for (int j = 0; j < 8; j++)
            t[i].push_back(x[j] & 15);
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int n, r;
        cin >> n >> r;
        n--;
        rotate(n, r == 1, true, true);
    }

    for (int i = 0, j = 1; i < 4; i++, j *= 2)
        ans += t[i][0] == 0 ? 0 : j;

    cout << ans;
}