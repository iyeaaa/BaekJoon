#include <iostream>
#include <algorithm>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int main() {
    FIO
    int n, a[2005], ans=0;
    
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a,a+n);
    
    for (int i=0; i<n; i++) {
        int lo=0, hi=n-1;
        while (lo < hi) {
            int sum = a[lo] + a[hi];
            if (sum == a[i]) {
                if (i == lo) lo++;
                else if (i == hi) hi--;
                else {
                    ans++;
                    break;
                }
            } 
            else if (sum < a[i]) lo++;
            else hi--;
        }
    }
    
    cout << ans;
}