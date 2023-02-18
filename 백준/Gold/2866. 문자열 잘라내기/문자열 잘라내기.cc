#include <iostream>
#include <vector>
#include <algorithm>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int r, c, ans;
string g[1001];
vector<string> sv;

int cmnLen(const string& x, const string& y) {
    for (int i=0; i<x.size(); i++)
        if (x[i] != y[i])
            return i;
    return r;
}

int main() {
    FIO
    cin >> r >> c;
    for (int i=0; i<r; i++) cin >> g[i];

    for (int i=0; i<c; i++) {
        string temp;
        for (int j=r-1; j>=0; j--)
            temp += g[j][i];
        sv.push_back(temp);
    }
    
    sort(sv.begin(),sv.end());
    
    for (int i=1; i<c; i++) {
        ans = max(ans, cmnLen(sv[i], sv[i-1]));
    }

    cout << r-ans-1;
}
