
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    string answer;

    cin >> N >> K;

    for (int i = 0; i < N; i++) answer += 'B';

    int cnt = 0;
    for (int i = 0; i < N-1 && K > 0; i++) if (N-i-1-cnt <= K)
        K -= (N-i-1-(cnt++)), answer[i] = 'A';

    if (K == 0) {
        cout << answer;
    } else {
        cout << -1;
    }
}

