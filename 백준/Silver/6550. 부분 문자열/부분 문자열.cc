
#include <iostream>
#include <algorithm>
using namespace std;

string s, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while (cin >> s >> t) {
        int idx = 0;
        for (char c: t) if (s[idx] == c) idx++;

        cout << (idx == s.size() ? "Yes" : "No") << '\n';
    }
}

