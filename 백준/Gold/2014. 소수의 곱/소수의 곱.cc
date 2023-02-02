
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long int lli;

int k, n, a[101];
lli MAX = lli(1) << 31;
priority_queue<lli, vector<lli>, greater<lli>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    lli ans = 0;

    cin >> k >> n;
    for (int i=0;i<k;i++)
        cin >> a[i], pq.push(a[i]);

    while (n--) {
        ans = pq.top(); pq.pop();
        for (int i = 0; i < k; i++) {
            if ((ans * a[i] >= MAX)) break;
            pq.push(ans * a[i]);
            if (ans % a[i] == 0) break;
        }
    }

    cout << ans;
}
