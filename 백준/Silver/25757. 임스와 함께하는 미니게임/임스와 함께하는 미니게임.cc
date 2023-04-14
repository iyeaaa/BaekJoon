#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

unordered_set<string> s;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    char k;
    cin >> n >> k;
    F(i, 0, n) {
        string x;
        cin >> x;
        s.insert(x);
    }

    cout << (k=='Y' ? s.size() : (k=='F' ? s.size()/2 : s.size()/3));
}