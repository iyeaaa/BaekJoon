#include <bits/stdc++.h>

#define fr(i, l, r) for(int i=l;i<r;i++)
using namespace std;

const int MAX = 1'000'001;
int N, vst[MAX], dp[MAX][2];
vector<int> tree[MAX];

void f(int x) {
    dp[x][0] = 0;
    dp[x][1] = 1;
    vst[x] = true;
    for (int nxt: tree[x]) if (!vst[nxt]) {
        f(nxt);
        dp[x][0] += dp[nxt][1];
        dp[x][1] += min(dp[nxt][0], dp[nxt][1]);
    }
    vst[x] = false;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> N;
    fr(i, 0, N-1) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    f(1);
    cout << min(dp[1][0], dp[1][1]);
}
