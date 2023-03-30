#include <bits/stdc++.h>

#define fr(i, l, r) for(int i=l;i<r;i++)
using namespace std;

int t;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> t;
    while (t--) {
        unordered_set<int> note;
        int n, m;
        cin >> n;
        fr(i, 0, n) {
            int x;
            cin >> x;
            note.insert(x);
        }
        cin >> m;
        fr(i, 0, m) {
            int x;
            cin >> x;
            cout << (note.find(x) != note.end()) << '\n';
        }
    }
}
