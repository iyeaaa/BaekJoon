
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    while (1) {
        cin >> n;
        if (n == -1) break;

        vector<int> l;
        int sum=0;
        for (int i=1; i<n; i++)
            if (n%i == 0)
                l.push_back(i),
                sum += i;
        if (sum == n) {
            cout << n << " = ";
            for (int i=0; i<l.size(); i++) {
                cout << l[i];
                if (i != l.size()-1)
                    cout << " + ";
            }
            cout << '\n';
        } else {
            cout << n << " is NOT perfect.\n";
        }
    }
}