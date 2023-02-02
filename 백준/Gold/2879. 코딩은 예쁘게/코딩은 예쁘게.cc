
#include <iostream>
#include <algorithm>
using namespace std;

int N, A[1001], x;

void solve() {
    int count = abs(A[N-1]), prev = A[0];
    for (int i = 1; i < N; prev = A[i++]) {
        if ((A[i] ^ prev) < 0)
            count += abs(prev);
        else if ((A[i] ^ (A[i] - prev)) < 0)
            count += abs(A[i] - prev);
    }
    cout << count;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> x, A[i] -= x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    input(), solve();
}
