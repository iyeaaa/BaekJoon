
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

int n, e, a, b, c, v1, v2, minDist[805];
vector<pii> g[805];


void Dijkstra(int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, start});
    fill(minDist, minDist+n+1, 99999999);
    minDist[start] = 0;

    while (!pq.empty()) {
        auto [dist, cur] = pq.top(); pq.pop();
        for (auto [edge, next]: g[cur]) if (dist+edge < minDist[next]) {
            pq.push({dist+edge, next});
            minDist[next] = dist+edge;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> e;
    for (int i = 0; i < e; i++)
        cin >> a >> b >> c,
        g[a].push_back({c, b}),
        g[b].push_back({c, a});
    cin >> v1 >> v2;

    Dijkstra(1);
    int sToV1 = minDist[v1], sToV2 = minDist[v2];
    
    Dijkstra(v1);
    int V1ToV2 = minDist[v2];
    int V1ToN = minDist[n];
    
    Dijkstra(v2);
    int V2ToN = minDist[n];

    int res1 = sToV1 + V1ToV2 + V2ToN;
    int res2 = sToV2 + V1ToV2 + V1ToN;

    if (res1 >= 99999999 && res2 >= 99999999)
        cout << -1;
    else
        cout << min(res1, res2);
}
