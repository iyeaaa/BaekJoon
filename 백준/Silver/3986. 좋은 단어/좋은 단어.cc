
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, ans = 0;
    string S;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> S;
        vector<char> stk;
        for (auto v: S) {
            if (stk.empty() || stk.back() != v)
                stk.push_back(v);
            else
                stk.pop_back();
        }
        ans += (stk.empty() ? 1 : 0);
    }

    cout << ans;
}