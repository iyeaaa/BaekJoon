
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#define FOR(i,l,r) for(int i=l;i<r;i++)
#define All(x) (x).begin(), (x).end()
using namespace std;

int v, e;
unordered_set<int> g[100001];
vector<pair<int, int>> articulation_lines;
int low[100001], pre[100001], cnt = 0;
int vst[100001];

void f(int x) {
    vst[x] = true;
    pre[x] = low[x] = ++cnt;

    for (int nxt: g[x]) {
        if (vst[nxt]) {
            low[x] = min(low[x], pre[nxt]);
        } else {
            g[nxt].erase(x);
            f(nxt);
            low[x] = min(low[x], low[nxt]);
            if (pre[x] < low[nxt])
                articulation_lines.push_back({min(x, nxt), max(x, nxt)});
        }
    }
}

void input() {
    cin >> v >> e;
    FOR(i, 0, e) {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
}

int main() {
    input();

    FOR(i, 1, v+1) if (!vst[i]) f(i);

    sort(All(articulation_lines));

    cout << articulation_lines.size() << '\n';
    for (auto [x, y]: articulation_lines)
        cout << x << ' ' << y << '\n';
}
