#include <iostream>
using namespace std;

bool send[31];

int main() {
    for (int i=0; i<28; i++) {
        int x; cin >> x;
        send[x] = 1;
    }
    for (int i=1; i<=30; i++)
        if (!send[i])
            cout << i << '\n';
}