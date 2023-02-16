#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, rmv, root;
int ans;
vector<int> g[51];

void dfs(int node) {
    if (g[node].empty()) {
        ans++;
        return;
    }
    for (auto child: g[node])
        dfs(child);
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        int p; cin >> p;
        if (p != -1)
            g[p].push_back(i);
        else
            root = i;
    }
    cin >> rmv;
    
    for (int i=0; i<N; i++) {
        auto idx = find(g[i].begin(), g[i].end(), rmv);
        if (idx != g[i].end())
            g[i].erase(idx);
    }
    
    if (rmv != root)
        dfs(root);
    
    cout << ans;
}