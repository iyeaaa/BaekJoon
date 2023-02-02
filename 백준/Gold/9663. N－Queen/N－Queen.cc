
#include <iostream>
#include <algorithm>
using namespace std;

int cnt, N, board[15];

bool promising(int cdx) {
    for (int i = 0; i < cdx; ++i)
        if (board[cdx] == board[i] || cdx-i == abs(board[cdx]-board[i]))
            return false;
    return true;
}

void nqueen(int cdx) {
    if (cdx == N) {
        cnt++;
        return;
    }
    for (int i = 0; i < N; i++) {
        board[cdx] = i;
        if (promising(cdx))
            nqueen(cdx + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    nqueen(0);
    cout << cnt;
}
