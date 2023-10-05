
#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,l,r) for(int i=l;i<r;i++)
#define All(x) (x).begin(), (x).end()
using namespace std;

int v, e;
vector<int> g[10001], gr[10001];

int gr_vst[10001];
vector<int> gr_post;

int scc_vst[10001];
vector<vector<int>> scc_s;

void explore_g(int x) {
    if (scc_vst[x]) return;
    scc_s.back().push_back(x);
    scc_vst[x] = true;
    for (int nxt: g[x]) explore_g(nxt);
}

void explore_gr(int x) {
    if (gr_vst[x]) return;
    gr_vst[x] = true;
    for (int nxt: gr[x]) explore_gr(nxt);
    gr_post.push_back(x);
}

void input() {
    cin >> v >> e;
    FOR(i, 0, e) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }
}

int main() {
    input();

    FOR(i, 1, v+1) if (!gr_vst[i]) explore_gr(i);
    reverse(All(gr_post));

    for (int x: gr_post) if (!scc_vst[x]) {
        scc_s.push_back({});
        explore_g(x);
    }

    for (vector<int>& scc: scc_s)
        sort(All(scc));
    sort(All(scc_s));

    cout << scc_s.size() << '\n';
    for (vector<int>& scc: scc_s) {
        for (int vertex: scc)
            cout << vertex << ' ';
        cout << "-1\n";
    }
}
