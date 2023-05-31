#include <bits/stdc++.h>

#define FIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define FOR(i, l, r) for (int i = l; i < r; i++)
using namespace std;
typedef pair<int, int> pii;

int n, m, a, b, c, s, t, mndist[5001];
vector<pii> g[100'001];
priority_queue<pii, vector<pii>, greater<>> pq;

int main() {
    FIO
    cin >> n >> m;
    FOR(i, 0, m)
        cin >> a >> b >> c,
        g[a].emplace_back(c, b),
        g[b].emplace_back(c, a);
    cin >> s >> t;
    fill(mndist, mndist+5000, 99999999);

    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [edge, cur] = pq.top();
        pq.pop();
        if (edge > mndist[cur]) continue;
        if (cur == t) break;
        for (auto [dist, nxt]: g[cur]) {
            if (edge + dist >= mndist[nxt]) continue;
            mndist[nxt] = edge + dist;
            pq.emplace(edge + dist, nxt);
        }
    }

    cout << mndist[t];
}