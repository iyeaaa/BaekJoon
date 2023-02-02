
#include <iostream>
using namespace std;

int A, B, C;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while(cin >> A >> B >> C) {
        cout << max(B-A, C-B)-1 << '\n';
    }
}
