#include <bits/stdc++.h>

#define fb(i, l, r) for (int i=l; i<r; i++)
#define ft(i, l, r) for (int i=l; i<=r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

int N, r , c;

void f(int len, int i, int j, int lo) {
    if (len == 1) {
        if (i == r && j == c) {
            cout << lo;
            exit(0);
        }
        return;
    }
    if (r < i + len/2 && c < j + len/2)
        f(len/2, i, j, lo);
    else if (r < i + len/2)
        f(len/2, i, j+len/2, lo + len/2*len/2);
    else if (c < j + len/2)
        f(len/2, i+len/2, j, lo + len/2*len/2*2);
    else
        f(len/2, i+len/2, j+len/2, lo + len/2*len/2*3);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> N >> r >> c;
    f((1<<N), 0, 0, 0);
}
