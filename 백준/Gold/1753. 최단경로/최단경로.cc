
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;

int v, e, k, x, y, w, mindist[20005];
vector<pii> g[20005];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> v >> e >> k;
    fill(mindist, mindist+1+v, 99999999);
    for (int i = 0; i < e; i++) {
        cin >> x >> y >> w;
        g[x].push_back({w, y});
    }
    pq.push({0, k});
    mindist[k] = 0;

    while (!pq.empty()) {
        auto [dist, cur] = pq.top(); pq.pop();
        for (auto [edge, next]: g[cur]) {
            if (dist + edge >= mindist[next]) continue;
            pq.push({edge+dist, next});
            mindist[next] = edge + dist;
        }
    }

    for (int i = 1; i <= v; i++) {
        if (mindist[i] == 99999999) cout << "INF";
        else cout << mindist[i];
        cout << "\n";
    }
}
