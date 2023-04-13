#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    while (true) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];

        if (a[0] == a[1] && a[1] == a[2] && a[2] == 0)
            break;

        sort(a, a+3);

        if (a[0] + a[1] <= a[2])
            cout << "Invalid";

        else if (a[0] == a[1] && a[1] == a[2])
            cout << "Equilateral";

        else if (a[0] == a[1] || a[1] == a[2])
            cout << "Isosceles";

        else cout << "Scalene";

        cout << '\n';
    }
}