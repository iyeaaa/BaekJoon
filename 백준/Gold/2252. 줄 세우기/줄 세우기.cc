#include <bits/stdc++.h>

#define fb(i, l, r) for (int i=l; i<r; i++)
#define ft(i, l, r) for (int i=l; i<=r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

const int MAX = 32001;
int n, m, edge[MAX];
vector<int> g[MAX], ans;
queue<int> q;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    fb(i, 0, m) {
        int a, b;
        cin >> a >> b;
        edge[b]++;
        g[a].push_back(b);
    }

    ft(i, 1, n) if (!edge[i]) q.push(i);

    while (!q.empty()) {
        int cur = q.front();
        ans.push_back(cur);
        q.pop();
        for (int nxt: g[cur])
            if (--edge[nxt] == 0)
                q.push(nxt);
    }

    for (int v: ans)
        cout << v << ' ';
}
