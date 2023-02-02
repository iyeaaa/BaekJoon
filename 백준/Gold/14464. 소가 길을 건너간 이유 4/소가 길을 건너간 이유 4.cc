
#include <iostream>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;
typedef tuple<ll, ll, ll> tll;
typedef vector<int> vi;

priority_queue<pii, vector<pii>, greater<pii>> pq;
int c, n, x, a, b, ans;
pii l[20000];
multiset<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> c >> n;
    for (int i = 0; i < c; i++)
        cin >> x, s.insert(x);
    for (int i = 0; i < n; i++)
        cin >> a >> b, pq.push({b, a});

    while (!pq.empty()) {
        auto [end, stt] = pq.top();
        auto iter = s.lower_bound(stt);
        if (iter != s.end() && (*iter) <= end)
            ans++, s.erase(iter);
        pq.pop();
    }

    cout << ans;
}
