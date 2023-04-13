#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int P;
    cin >> P;
    while (P--) {
        int t, ans = 0;
        vector<int> key = {0, };
        cin >> t;
        F(i, 1, 21) {
            int x;
            cin >> x;
            key.push_back(x);
            F(j, 1, i) {
                if (x < key[j]) {
                    ans += i - j;
                    key.insert(key.begin()+j, x);
                    key.pop_back();
                    break;
                }
            }
        }
        cout << t << ' ' << ans << '\n';
    }
}