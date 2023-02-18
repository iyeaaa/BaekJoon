#include <iostream>
#include <algorithm>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int t;

int main() {
    FIO
    cin >> t;
    
    while (t--) {
        int n, k, s[1'000'001];
        int mn = 999'999'999, mnCnt = 1;
        
        cin >> n >> k;
        for (int i=0; i<n; i++) cin >> s[i];
        
        sort(s, s+n);
        
        int lo=0, hi=n-1;
        while (lo < hi) {
            int sum = s[lo] + s[hi];
            int dist = abs(sum-k);
            if (mn > dist) {
                mn = dist;
                mnCnt = 1;
            } else if (mn == dist) {
                mnCnt++;
            }
            if (sum < k) lo++;
            else hi--;
        }
        
        cout << mnCnt << '\n';
    }
}