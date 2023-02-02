
#include <iostream>
#include <algorithm>
using namespace std;

int NOT_self[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 1; i <= 10000; i++) {
        string n = to_string(i);
        int next = i;
        for (auto e: n)
            next += e-48;

        if (next > 10000)
            continue;

        NOT_self[next] = true;
    }

    for (int i = 1; i <= 10000; i++)
        if (!NOT_self[i])
            cout << i << '\n';
}
