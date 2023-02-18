#include <iostream>
#include <algorithm>
using namespace std;

int n, h;
int up[100'005], down[100'005];
int mn = 99999999, mnCnt = 0;

int main() {
    cin >> n >> h;
    for (int i=0; i<n; i++)
        cin >> (i%2 == 0 ? down[i/2] : up[i/2]);
    for (int i=0; i<n/2; i++)
        up[i] = h - up[i];
    
    sort(up, up+n/2);
    sort(down, down+n/2);
    
    for (int i=1; i<=h; i++) {
        int obs = 0;
        obs += n/2 - (lower_bound(down,down+n/2,i) - down);
        obs += lower_bound(up,up+n/2,i) - up;
        if (mn > obs) {
            mn = obs;
            mnCnt = 1;
        } else if (mn == obs) {
            mnCnt++;
        }
    }
    
    cout << mn << ' ' << mnCnt;
}