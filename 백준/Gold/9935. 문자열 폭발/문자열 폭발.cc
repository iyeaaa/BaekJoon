
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string S, b;
    string save = "";
    cin >> S >> b;
    int blen = b.size();

    for (int i = 0; i < S.size(); i++) {
        save += S[i];
        int slen = save.size();
        if (slen < blen) continue;
        if (save.substr(slen-blen, blen) != b) continue;
        for (int j = 0; j < blen; j++) save.pop_back();
    }

    cout << (save.empty() ? "FRULA" : save);
}