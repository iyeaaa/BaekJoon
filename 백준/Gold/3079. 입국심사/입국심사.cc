#include <iostream>
#include <vector>
#include <algorithm>
#define FIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;

ll n, m;
vector<int> t;

bool isPsb(ll x) {
    ll sum = 0;
    for (auto v: t) {
        sum += x/v;
        if (sum >= m)
            return true;
    }
    return sum >= m;
}

int main() {
    FIO
    
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        t.push_back(x);
    }
    
    ll lo = 0, hi = (*max_element(t.begin(),t.end()))*m+1;
    while (lo+1 < hi) {
        ll mid = (lo + hi) >> 1;
        if (isPsb(mid)) hi = mid;
        else lo = mid;
    }
    
    cout << hi;
}