
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;
typedef tuple<ll, ll, ll> tll;
typedef vector<int> vi;

priority_queue<int, vector<int>, less<int>> pq;
ll n, k, c[300001], m, v, ans;
vector<pii> ruby;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> m >> v,
        ruby.push_back({m, v});
    sort(ruby.begin(), ruby.end(), greater<pii>());

    for (int i = 0; i < k; i++)
        cin >> c[i];
    sort(c, c+k);

    for (int i = 0; i < k; i++) {
        int cur = c[i];
        while (!ruby.empty() && cur >= ruby.back().first)
            pq.push(ruby.back().second), ruby.pop_back();
        if (!pq.empty())
            ans += pq.top(), pq.pop();
    }

    cout << ans;
}
