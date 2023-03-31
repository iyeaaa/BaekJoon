#include <bits/stdc++.h>

#define F(i, l, r) for (int i=l; i<r; i++)
using namespace std;

int n, A[10000];
long long ans;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;
    F(i, 0, n) cin >> A[i];
    sort(A, A + n);

    F(i, 0, n) {
        int lo = i+1;
        int hi = n-1;
        while (lo < hi) {
            if (A[i] + A[lo] + A[hi] > 0) hi--;
            else if (A[i] + A[lo] + A[hi] < 0) lo++;
            else if (A[lo] == A[hi]) {
                ans += (hi - lo + 1) * (hi - lo) / 2;
                break;
            } else {
                int flo = A[lo], fhi = A[hi];
                int locnt = 0, hicnt = 0;
                while (flo == A[lo]) lo++, locnt++;
                while (fhi == A[hi]) hi--, hicnt++;
                ans += locnt * hicnt;
            }
        }
    }

    cout << ans;
}
