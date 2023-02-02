
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

priority_queue<pii, vector<pii>, greater<pii>> pq;
int n, m, minDist[2][1001], a, b, c, s, e;
vector<pii> g[1001];
vector<int> route;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> a >> b >> c,
        g[a].push_back({c, b});
    cin >> s >> e;

    fill(minDist[0], minDist[0]+1+n, 99999999);
    pq.push({0, s});
    minDist[0][s] = 0;

    while (!pq.empty()) {
        auto [dist, cur] = pq.top(); pq.pop();
        if (cur == e) break;
        for (auto [edge, next]: g[cur]) {
            if (dist + edge >= minDist[0][next]) continue;
            minDist[0][next] = dist + edge;
            pq.push({minDist[0][next], next});
            minDist[1][next] = cur;
        }
    }

    route.push_back(e);
    while (minDist[1][route.back()])
        route.push_back(minDist[1][route.back()]);

    cout << minDist[0][e] << '\n';
    cout << route.size() << '\n';
    for (int i = route.size() - 1; i >= 0; --i)
        cout << route[i] << ' ';
}
