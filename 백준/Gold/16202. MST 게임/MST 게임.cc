#include <bits/stdc++.h>

#define fb(i, l, r) for (int i=l; i<r; i++)
#define ft(i, l, r) for (int i=l; i<=r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

struct disjoint_set {
    int p[1001], rank[1001];

    disjoint_set() { ft(i, 0, 1000) p[i] = i; }

    int root(int x) {
        return p[x] == x ? x : (p[x] = root(p[x]));
    }

    void uni(int y, int x) {
        y = root(y), x = root(x);
        if (rank[y] < rank[x]) p[x] = y;
        else p[y] = x;
        if (rank[y] == rank[x]) rank[y]++;
    }

    bool isuni(int y, int x) {
        return root(y) == root(x);
    }
};

int n, m, k;
set<tuple<int,int,int>> edges;

int mstScore() {
    disjoint_set uf;
    tuple<int, int, int> rmvd = {999999, 0, 0};
    int edgecnt = 0;
    int rtn = 0;

    for (auto [d, x, y]: edges) if (!uf.isuni(y, x)) {
        uf.uni(y, x);
        rmvd = min(rmvd, {d, x, y});
        edgecnt++;
        rtn += d;
    }

    if (edgecnt != n-1)
        return 0;

    edges.erase(rmvd);

    return rtn;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    ft(i, 1, m) {
        int x, y;
        cin >> x >> y;
        edges.insert({i, x, y});
    }

    fb(i, 0, k) cout << mstScore() << ' ';
}
