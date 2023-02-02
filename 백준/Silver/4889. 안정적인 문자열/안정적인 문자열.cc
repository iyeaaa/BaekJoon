
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 1;; i++) {
        string strn; cin >> strn;
        int open = 1, close = 1;

        if (strn[0] == '-') break;

        for (int j = 0; j < strn.size(); j++) {
            if (strn[j] == '{') open++;
            else if (open > 1) open--;
            else close++;
        }

        cout << i << ". " << open/2 + close/2 << '\n';
    }
}
