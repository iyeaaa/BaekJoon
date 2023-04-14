#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

bool isChl(char c) {
    return c != 'a' && c != 'e' && c != 'o' && c != 'i' && c != 'u';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    while (true) {
        first: string x;
        cin >> x;

        if (x == "end")
            break;

        if (x.find('a') == -1) {
            if (x.find('e') == -1)
                if (x.find('i') == -1)
                    if (x.find('o') == -1)
                        if (x.find('u') == -1) {
                            cout << ("<" + x + "> is not acceptable.\n");
                            goto first;
                        }
        }

        F(i, 2, x.size()) {
            if (isChl(x[i-2]) && isChl(x[i-1]) && isChl(x[i])) {
                cout << ("<" + x + "> is not acceptable.\n");
                goto first;
            } else if (!isChl(x[i-2]) && !isChl(x[i-1]) && !isChl(x[i])) {
                cout << ("<" + x + "> is not acceptable.\n");
                goto first;
            }
        }

        F(i, 1, x.size()) {
            if (x[i - 1] == x[i] && x[i] != 'e' && x[i] != 'o') {
                cout << ("<" + x + "> is not acceptable.\n");
                goto first;
            }
        }

        cout << ("<" + x + "> is acceptable.\n");
    }
}