#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define FOR(i, l, r) for (int i = l; i < r; i++)
using namespace std;

// f(a, x): 마지막에 x칸 점프해서 n번째 돌에 도달하는 최소 점프 횟수
// f(a, x) = min(f(a-x, x-1), f(a-x, x), f(a-x, x+1)) + 1

const int INF = 999999999;
int n, m, memo[10001][151], ans = INF;
bool isSmall[10001];

int f(int a, int x) {
    if (a == 1 && x == 0) return 0;
    if (a <= 0 || isSmall[a] || x <= 0 || x >= 151) return INF;
    if (~memo[a][x]) return memo[a][x];
    int temp = INF;
    temp = min(temp, f(a-x, x-1) + 1);
    temp = min(temp, f(a-x, x) + 1);
    temp = min(temp, f(a-x, x+1) + 1);
    return memo[a][x] = temp;
}

int main() {
//    FIO freopen("input.txt", "r", stdin);
    memset(memo, -1, sizeof(memo));
    cin >> n >> m;
    FOR(i, 0, m) {
        int x;
        cin >> x;
        isSmall[x] = true;
    }
    FOR(i, 1, 150)
        ans = min(ans, f(n, i));
    cout << (ans == INF ? -1 : ans);
}

// 1 2 3 4 5 6 7 8