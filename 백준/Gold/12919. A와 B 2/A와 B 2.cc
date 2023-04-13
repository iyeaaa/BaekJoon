#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

string s, t;

bool f(string t) {
    if (s.size() == t.size())
        return s == t;
    if (t.back() == 'A')
        if (f(t.substr(0, t.size() - 1)))
            return true;
    if (t.front() == 'B') {
        string temp;
        for (int i= t.size() - 1; i > 0; i--)
            temp += t[i];
        if (f(temp))
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> s >> t;
    cout << f(t);
}