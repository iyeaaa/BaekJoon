
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

int n, a[500001], sum = 0;

void solve() {
    ll answer = 0;
    for (int i = 0; i < n; i++)
        answer += a[i] * (sum - a[i]), sum -= a[i];
    cout << answer;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];
    sort(a, a+n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    input(), solve();
}

