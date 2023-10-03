
#include <iostream>
#include <set>
#include <vector>
#define FOR(i,l,r) for(int i=l;i<r;i++)
#define All(x) (x).begin(), (x).end()
using namespace std;

int v, e, vst[10001], low[10001], pre[10001], cnt;
vector<int> g[10001];
set<int> articulation_points;

void f(int prnt, int p = 0) {
    vst[prnt] = true;
    pre[prnt] = low[prnt] = cnt++;
    int child_cnt = 0;
    for (int child: g[prnt]) {
        if (vst[child]) {
            low[prnt] = min(low[prnt], pre[child]);
        } else {
            f(child, prnt);
            low[prnt] = min(low[prnt], low[child]);
            if (p != 0 && pre[prnt] <= low[child])
                articulation_points.insert(prnt);
            child_cnt++;
        }
    }
    if (p == 0 && child_cnt > 1)
        articulation_points.insert(prnt);
}

void input() {
    cin >> v >> e;
    FOR(i, 0, e) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

int main() {
    input();

    FOR(i, 1, v+1) if (!vst[i]) f(i);

    cout << articulation_points.size() << '\n';
    for (int x: articulation_points)
        cout << x << ' ';
}
