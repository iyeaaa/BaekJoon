
#include <iostream>
#include <algorithm>
using namespace std;

int C, K, T[1001], N;

bool solve() {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                if (T[i]+T[j]+T[k] == K)
                    return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for (N = 1; N * (N + 1) / 2 < 1000; N++)
        T[N] = N * (N + 1) / 2;
    N--;

    cin >> C;
    while (C--) {
        cin >> K;
        cout << solve() << '\n';
    }
}