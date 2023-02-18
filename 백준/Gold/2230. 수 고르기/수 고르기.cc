#include <iostream>
#include <algorithm>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, m, a[100'005];
int ans = 2'000'000'006;

int main() {
    FIO
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];
    
    sort(a, a+n);
    
    int lo=0, hi=0;
    while (hi < n && lo <= hi) {
        int diff = a[hi] - a[lo];
        if (m <= diff) lo++, ans = min(ans, diff);
        else hi++;
    }
    
    cout << ans;
}