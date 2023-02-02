
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int milk = 0;
    int count = 0;

    while (N--) {
        int x; cin >> x;
        if (milk == x) {
            count++;
            milk = (milk+1) % 3;
        }
    }

    cout << count;
}