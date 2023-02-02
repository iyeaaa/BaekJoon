
#include <iostream>
#include <algorithm>
using namespace std;

int P[9], sum;

void solve() {
    for (int i = 0; i < 9; i++) {
        for (int j = i+1; j < 9; j++) {
            if (sum - P[i] - P[j] != 100)
                continue;
            for (int k = 0; k < 9; k++) {
                if (k == i || k == j)
                    continue;
                cout << P[k] << '\n';
            }
            return;
        }
    }
}

void input() {
    for (int i = 0; i < 9; i++)
        cin >> P[i], sum += P[i];
    sort(P, P+9);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    input(), solve();
}
