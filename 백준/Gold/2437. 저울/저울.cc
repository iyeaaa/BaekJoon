
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    int L[1001]; for(int i=0;i<N;i++) cin >> L[i];
    sort(L, L+N);

    int S = 0;
    for (int i = 0; i < N; i++)
        if (S+1 < L[i]) break;
        else S += L[i];

    cout << S+1;
}