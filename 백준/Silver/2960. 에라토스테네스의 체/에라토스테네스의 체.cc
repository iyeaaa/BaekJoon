#include <bits/stdc++.h>

#define fb(i, l, r) for (int i=l; i<r; i++)
#define ft(i, l, r) for (int i=l; i<=r; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

bool isPrime[1001];

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, k, cnt = 0;
    cin >> n >> k;
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i; j <= n; j += i) {
                if (isPrime[j]) {
                    isPrime[j] = false;
                    cnt++;
                    if (cnt == k) {
                        cout << j;
                        exit(0);
                    }
                }
            }
        }
    }
}
