
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

int t, n, d, c, mindist[10001], a, b, s;
vector<pii> g[10001];

void solve() {
    cin >> n >> d >> c;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int ans_t = 0, ans_cnt = 0;

    fill(begin(mindist), end(mindist), 99999999);
    fill(begin(g), end(g), vector<pii>());

    for (int i = 1; i <= d; i++)
        cin >> a >> b >> s,
        g[b].push_back({s, a});
    mindist[c] = 0;
    pq.push({0, c});

    while (!pq.empty()) {
        auto [dist, cur] = pq.top(); pq.pop();
        if (dist > mindist[cur]) continue;
        for (auto [edge, next]: g[cur]) if (edge+dist < mindist[next]) {
            mindist[next] = edge + dist;
            pq.push({mindist[next], next});
        }
    }

    for (int i = 1; i <= n; i++) if (mindist[i] != 99999999)
        ans_cnt++, ans_t = max(ans_t, mindist[i]);

    cout << ans_cnt << ' ' << ans_t << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> t; while(t--) solve();
}
