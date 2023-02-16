#include <iostream>
#include <algorithm>
using namespace std;

int tree[10001];

void dfs(int lo, int hi) {
    if (lo >= hi) return;
    auto it = upper_bound(tree+lo, tree+hi, tree[lo]);
    int mid = distance(tree, it);
    dfs(lo+1, mid);
    dfs(mid, hi);
    cout << tree[lo] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int i=0;
    while (cin>>tree[i++]);
    dfs(0, i-1);
}