#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int C(int n, int k) {
    int d[31]={1,0};
    for (int i=1; i<=n; i++)
        for (int j=min(i,k); j>0; j--)
            d[j] += d[j-1];
    return d[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin>>T;
    while (T--) {
        int N, M; cin >> N >> M;
        cout << C(M, N) << '\n';
    }
}