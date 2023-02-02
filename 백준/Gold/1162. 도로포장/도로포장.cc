
// f(n, k): k개의 도로를 포장했을 때, n번 도시로 가는 최소시간.
// f(n, k) = min(f(child(n), k-1), f(child(n), k) + dist(chl(n) -> n))

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

int n, m, k, a, b, c;
ll mindist[10001][21];
ll MAX = 9223372036854775800;
vector<pii> g[10001];
priority_queue<tll, vector<tll>, greater<tll>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> a >> b >> c,
        g[a].push_back({c, b}),
        g[b].push_back({c, a});
    fill(&mindist[0][0], &mindist[10000][21], MAX);

    pq.push({0, 1, 0});
    mindist[1][0] = 0;

    while (!pq.empty()) {
        auto [dist, cur, cur_cnt] = pq.top(); pq.pop();
        if (dist > mindist[cur][cur_cnt]) continue;
        for (auto [edge, next]: g[cur]) {
            if (cur_cnt < k && dist < mindist[next][cur_cnt+1]) {
                mindist[next][cur_cnt+1] = dist;
                pq.push({mindist[next][cur_cnt+1], next, cur_cnt+1});
            }
            if (dist + edge < mindist[next][cur_cnt]) {
                mindist[next][cur_cnt] = dist + edge;
                pq.push({mindist[next][cur_cnt], next, cur_cnt});
            }
        }
    }

    cout << *min_element(mindist[n]+1, mindist[n]+k+1);
}
