
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int answer = 0;
    bool start = false;
    string L, R;
    cin >> L >> R;

    if (L.size() != R.size()) {
        cout << 0; return 0;
    }

    for (int i = 0; i < L.size(); i++)
        if (L[i] == '8' && R[i] == '8') answer++;
        else if (L[i] != R[i]) break;

    cout << answer;
}
