
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int lli;

lli n, k, ans;
string s;
queue<int> q[21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> s;
        int len = s.length();
        while (!q[len].empty() && i-q[len].front() > k)
            q[len].pop();
        ans += q[len].size();
        q[len].push(i);
    }

    cout << ans;
}
