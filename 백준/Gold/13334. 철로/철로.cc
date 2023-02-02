
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> pll;

int n;
lli d, ans = 0, x, y, last;
pll l[100005];
priority_queue<pll, vector<pll>, greater<pll>> q;

bool cmp(const pll &a, const pll &b) {
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x >> y,
        l[i] = {min(x, y), max(x, y)};
    cin >> d;
    sort(l, l+n, cmp);

    for (int i = 0; i < n; i++) {
        q.push(l[i]);
        last = l[i].second;
        while (!q.empty() && q.top().first < last - d)
            q.pop();
        ans = max(ans, (lli)q.size());
    }

    cout << ans;
}
