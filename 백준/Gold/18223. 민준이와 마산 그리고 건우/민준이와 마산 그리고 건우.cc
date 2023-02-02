
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

int v, e, p, a, b, c, md[5001];
vector<pii> g[5001];

void dijkstra(int s) {
    fill(md, md+5001, 99999999);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    md[s] = 0;

    while (!pq.empty()) {
        auto [dist, cur] = pq.top(); pq.pop();
        if (dist > md[cur]) continue;
        for (auto [edge, next]: g[cur]) {
            if (dist + edge >= md[next]) continue;
            md[next] = dist + edge;
            pq.push({md[next], next});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> v >> e >> p;
    for (int i = 0; i < e; i++)
        cin >> a >> b >> c,
        g[a].push_back({c, b}),
        g[b].push_back({c, a});

    dijkstra(1);
    int SToN = md[v];
    dijkstra(p);

    cout << (SToN == md[1] + md[v] ? "SAVE HIM" : "GOOD BYE");
}
