#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

int n, w, vst[500'001], leafcnt;
vector<int> g[500'001];
queue<int> q;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> w;
    F(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    q.push(1);
    vst[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        bool exist = false;
        for (int nxt: g[cur]) if (!vst[nxt]) {
            exist = true;
            q.push(nxt);
            vst[nxt] = true;
        }
        leafcnt += !exist;
    }

    cout.precision(4);
    cout << fixed << (1.0 * w / leafcnt) << endl;
}