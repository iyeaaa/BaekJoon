
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, V[10], sum;
vector<long> L[11];

void dfs(int depth, int digit, int idx, long cur) {
    if (digit == depth) {
        L[depth].push_back(cur);
        return;
    }
    for (int i = idx; i >= 0; i--) if (!V[i]) {
        V[i] = true;
        dfs(depth, digit+1, i-1, cur*10+i);
        V[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;

    if (N <= 10) { cout << N-1; return 0; }

    dfs(1, 0, 9, 0);
    sum = 10;
    for (int i = 2; i <= 10; i++) {
        dfs(i, 0, 9, 0);
        if (sum + L[i].size() >= N) {
            cout << L[i][L[i].size()-(N-sum)];
            return 0;
        }
        sum += L[i].size();
    }

    cout << -1;
}