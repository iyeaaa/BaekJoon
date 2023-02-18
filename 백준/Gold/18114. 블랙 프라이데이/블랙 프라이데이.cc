#include <iostream>
#include <algorithm>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int n, c, w[5005];
bool ans = false;

int main() {
    cin >> n >> c;
    for (int i=0; i<n; i++) cin >> w[i], ans=max(ans,w[i]==c);
    sort(w, w+n);
    
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            ans = max(ans, w[i]+w[j] == c);
    
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++) {
            int k = lower_bound(w+j+1,w+n,c-w[i]-w[j]) - w;
            ans = max(ans, w[i] + w[j] + w[k] == c);
        }
    
    cout << ans;
}