#include <iostream>
#include <vector>
using namespace std;

int t;
vector<int> tree;

// lo is Root
void dfs(int lo, int hi) {
    if (lo > hi)
        return;
    if (lo == hi) {
        cout << tree[lo] << '\n';
        return;
    }
    int flag = false;
    for (int i=lo+1; i<=hi; i++) {
        if (tree[lo] < tree[i]) {
            dfs(lo+1, i-1);
            dfs(i, hi);
            flag = true;
            break;
        }
    }
    if (!flag)
        dfs(lo+1, hi);
    cout << tree[lo] << '\n';
}

int main() {
    while (cin >> t)
        tree.push_back(t);

    dfs(0, tree.size()-1);
}