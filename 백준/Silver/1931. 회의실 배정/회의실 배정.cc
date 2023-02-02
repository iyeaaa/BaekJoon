
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int N;
pii D[100001];

bool oper(const pii &a, const pii &b) {
    return a.second != b.second ? a.second < b.second : a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> D[i].first >> D[i].second;
    sort(D, D+N, oper);

    int lastTime = 0;
    int cnt = 0;
    for (auto [s, e]: D) if (lastTime <= s)
        lastTime = e, cnt++;

    cout << cnt;
}