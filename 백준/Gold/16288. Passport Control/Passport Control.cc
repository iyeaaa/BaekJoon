
#include <iostream>
#include <queue>
using namespace std;

int N, k, L[101], V[101], cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> k;
    for (int i = 0; i < N; i++) cin >> L[i];

    for (int i = 0; i < N; i++) if (!V[i]) {
        cnt++;
        int cur = i;
        for (int j = i+1; j < N; j++) if (!V[j] && L[cur] < L[j])
            V[j] = true, cur = j;
    }

    cout << (cnt <= k ? "YES" : "NO");
}
