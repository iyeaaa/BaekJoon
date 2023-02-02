
#include <iostream>
#include <algorithm>
using namespace std;

bool isFourOrSeven(string str) {
    for (char c: str)
        if (c != '4' && c != '7')
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;

    for (int i = N; i >= 0; --i) {
        if (isFourOrSeven(to_string(i))) {
            cout << i;
            break;
        }
    }
}