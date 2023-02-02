
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

priority_queue<pii, vector<pii>, greater<pii>> pq;
int n, m, x, y, z, mindist[1001], parent[1001], save[1001], ans;
vector<pii> g[1001];

int dijkstra(int s, int e) {
    pq = priority_queue<pii, vector<pii>, greater<pii>>();
    fill(mindist, mindist+1001, 99999999);
    mindist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [dist, cur] = pq.top(); pq.pop();
        if (cur == n) break;
        if (dist > mindist[cur]) continue;
        for (auto [edge, next]: g[cur]) if (dist+edge < mindist[next]) {
            if (cur==s && next==e || cur==e && next==s) continue;
            mindist[next] = edge + dist;
            pq.push({mindist[next], next});
            parent[next] = cur;
        }
    }

    return mindist[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> x >> y >> z,
        g[x].push_back({z, y}),
        g[y].push_back({z, x});

    dijkstra(0, 0);
    int start = n;

    for (int i = 1; i <= 1000; i++)
        save[i] = parent[i];

    while (parent[start] != 0) {
        ans = max(ans, dijkstra(start, save[start]));
        start = save[start];
    }

    cout << ans;
}
