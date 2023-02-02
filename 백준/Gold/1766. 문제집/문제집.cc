
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int n, m, e[32004], a, b;
vector<int> g[32004];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;

    for (int i = 0; i < m; i++)
        cin >> a >> b, g[a].push_back(b), e[b]++;

    for (int i = 1; i <= n; i++) if (!e[i]) pq.push(i);

    while (!pq.empty()) {
        int cur = pq.top(); cout << cur << ' '; pq.pop();
        for (int next: g[cur]) {
            e[next]--;
            if (!e[next]) pq.push(next);
        }
    }
}
