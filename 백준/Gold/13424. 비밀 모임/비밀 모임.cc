
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int> tii;
typedef tuple<ll, ll, ll> tll;
typedef vector<int> vi;

ll t, n, m, dist[101][101], a, b, c, k, l[101];

void solve() {
    cin >> n >> m;
    fill(&dist[0][0], &dist[100][101], 9999999999);

    for (int i = 1; i <= n; i++) dist[i][i] = 0;

    for (int i = 1; i <= m; i++)
        cin >> a >> b >> c,
        dist[a][b] = c,
        dist[b][a] = c;
    cin >> k;

    for (int i = 0; i < k; i++)
        cin >> l[i];

    for (int mid = 1; mid <= n; mid++)
        for (int s = 1; s <= n; s++)
            for (int e = 1; e <= n; e++)
                if (dist[s][mid] + dist[mid][e] < dist[s][e])
                    dist[s][e] = dist[s][mid] + dist[mid][e];

    ll ans = 1;
    ll prev = 99999999999;
    for (int i = 1; i <= n; i++) {
        int temp = 0;
        for (int j = 0; j < k; j++) temp += dist[i][l[j]];
        if (temp < prev) ans = i, prev = temp;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    while (t--) solve();
}
