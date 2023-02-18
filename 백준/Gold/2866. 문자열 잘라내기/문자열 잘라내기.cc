#include <iostream>
#include <unordered_set>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int r, c, cnt;
string g[1001];
unordered_set<string> s;

void contains(const unordered_set<string>& us, const string& str) {
    if (us.find(str) != us.end()) {
        cout << cnt;
        exit(0);
    }
}

int main() {
    FIO
    cin >> r >> c;
    for (int i=0; i<r; i++) cin >> g[i];

    for (int i=0; i<c; i++) {
        string temp;
        for (int j=r-1; j>=0; j--)
            temp += g[j][i];
        contains(s, temp);
        s.insert(temp);
    }

    for (int i=0; i<r; i++) {
        unordered_set<string> temp;
        for (string str: s) {
            str.pop_back();
            contains(temp, str);
            temp.insert(str);
        }
        s = temp;
        cnt++;
    }

    cout << cnt;
}
