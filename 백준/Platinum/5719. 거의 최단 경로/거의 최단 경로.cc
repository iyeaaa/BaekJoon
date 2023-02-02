
// T.C: O(M)/2 * O(M*logN) = 5천만

#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;
typedef tuple<ll, ll, ll> tll;
typedef vector<int> vi;

int n, m, md[501], s, d, u, v, p, rmvd[501][501];
vector<pii> g[501];
vector<int> parent[501];

int dijkstra() {
    fill(md, md+501, 99999999);
    fill(parent, parent+501, vector<int>());
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    md[s] = 0;

    while (!pq.empty()) {
        auto [dist, cur] = pq.top(); pq.pop();
        if (dist > md[cur]) continue;
        for (auto [edge, next]: g[cur]) {
            if (rmvd[cur][next]) continue;
            if (dist+edge > md[next]) continue;
            if (dist+edge == md[next]) {
                parent[next].push_back(cur);
            } else {
                md[next] = dist + edge;
                pq.push({md[next], next});
                parent[next].clear();
                parent[next].push_back(cur);
            }
        }
    }

    return md[d];
}

void rmvEdge() {
    int visit[501] = {false, };
    queue<int> q; q.push(d), visit[d] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int next: parent[cur]) {
            rmvd[next][cur] = true;
            if (visit[next]) continue;
            visit[next] = true;
            q.push(next);
        }
    }
}

void solve() {
    fill(g, g+501, vector<pii>());
    fill(&rmvd[0][0], &rmvd[500][501], false);
    cin >> s >> d;
    for (int i = 0; i < m; i++)
        cin >> u >> v >> p,
        g[u].push_back({p, v});

    dijkstra();
    rmvEdge();
    int second = dijkstra();
    cout << (second == 99999999 ? -1 : second) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        solve();
    }
}
