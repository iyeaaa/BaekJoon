
#include <iostream>
#include <algorithm>
using namespace std;

int N, C[1001], memo[1001][1001];

int f(int i, int j, bool Gturn) {
    if (i > j) return 0;
    if (memo[i][j] > 0) return memo[i][j];
    int score;

    if (Gturn) {
        score = max(f(i+1, j, !Gturn) + C[i], f(i, j-1, !Gturn) + C[j]);
    } else {
        score = min(f(i+1, j, !Gturn), f(i, j-1, !Gturn));
    }

    memo[i][j] = score;
    return score;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> C[i];
    for (int i=1;i<=N;i++) for(int j=1;j<=N;j++) memo[i][j] = 0;

    cout << f(1, N, true) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while (T--) solve();
}