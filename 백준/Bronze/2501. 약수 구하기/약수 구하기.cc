
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int cnt = 0;
    int N, K;

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        if (N%i == 0) cnt++;
        if (cnt == K) {
            cout << i;
            return 0;
        }
    }

    cout << 0;
}