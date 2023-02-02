
// T.C: O(N*N*

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

int n, m, a, b, d, foxdist[4001], wolfdist[4001][2], ans;
vector<pii> g[4001];

void wolf_dkstra() {
    priority_queue<tii, vector<tii>, greater<tii>> pq;
    pq.push({0, 1, true});
    while (!pq.empty()) {
        auto [dist, cur, fast] = pq.top(); pq.pop();
        if (dist > wolfdist[cur][fast]) continue;
        for (auto [edge, next]: g[cur]) {
            int realEdge = fast ? edge/2 : edge*2;
            if (realEdge + dist >= wolfdist[next][!fast]) continue;
            pq.push({realEdge + dist, next, !fast});
            wolfdist[next][!fast] = realEdge + dist;
        }
    }
}

void fox_dkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [dist, cur] = pq.top(); pq.pop();
        if (dist > foxdist[cur]) continue;
        for (auto [edge, next]: g[cur]) {
            if (edge+dist >= foxdist[next]) continue;
            pq.push({dist+edge, next});
            foxdist[next] = dist + edge;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a >> b >> d,
        g[a].push_back({d*2, b}),
        g[b].push_back({d*2, a});
    fill(foxdist, foxdist+4001, 999999999);
    fill(&wolfdist[0][0], &wolfdist[4000][2], 999999999);
    foxdist[1] = 0;
    wolfdist[1][1] = 0;

    fox_dkstra(); wolf_dkstra();

    for (int i = 2; i <= n; i++)
        if (foxdist[i] < min(wolfdist[i][0], wolfdist[i][1]))
            ans++;

    cout << ans;
}
