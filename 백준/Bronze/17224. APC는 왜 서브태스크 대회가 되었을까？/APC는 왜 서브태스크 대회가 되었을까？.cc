
#include <iostream>
using namespace std;

int N, L, K, x, y, sub1=0, sub2=0;

void solve() {
    cout << (sub2 > K ? 140*K : sub2*140 + (K-sub2 < sub1 ? (K-sub2)*100 : sub1*100));
}

void input() {
    cin >> N >> L >> K;
    for (int i=0;i<N;i++) {
        cin >> x >> y;
        if (y <= L) sub2++;
        else if (x <= L) sub1++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    input(), solve();
}
