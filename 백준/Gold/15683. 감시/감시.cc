
#include <vector>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

int N, M, ans=9999999;
vector<pii> CCTV;
vvi G(9, vector<int>(9));

vvi down(int y, int x, vvi V) {
    for (int i = y+1; i < N; i++) {
        if (V[i][x] == 6) {
            break;
        } else {
            V[i][x] = -1;
        }
    }
    return V;
}

vvi up(int y, int x, vvi V) {
    for (int i = y-1; i >= 0; i--) {
        if (V[i][x] == 6) {
            break;
        } else  {
            V[i][x] = -1;
        }
    }
    return V;
}

vvi ryt(int y, int x, vvi V) {
    for (int i = x+1; i < M; i++) {
        if (V[y][i] == 6) {
            break;
        } else {
            V[y][i] = -1;
        }
    }
    return V;
}

vvi lf(int y, int x, vvi V) {
    for (int i = x-1; i >= 0; i--) {
        if (V[y][i] == 6) {
            break;
        } else {
            V[y][i] = -1;
        }
    }
    return V;
}

void dfs(int idx, vvi V) {
    if (idx == CCTV.size()) {
        int sum = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (V[i][j] == 0) sum += 1;
        ans = min(ans, sum);
        return;
    }

    int y = CCTV[idx].first;
    int x = CCTV[idx].second;

    if (G[y][x] == 1) {
        dfs(idx+1, down(y, x, V));
        dfs(idx+1, up(y, x, V));
        dfs(idx+1, lf(y, x, V));
        dfs(idx+1, ryt(y, x, V));
    } else if (G[y][x] == 2) {
        dfs(idx+1, lf(y, x, ryt(y, x, V)));
        dfs(idx+1, up(y, x, down(y, x, V)));
    } else if (G[y][x] == 3) {
        dfs(idx+1, up(y, x, ryt(y, x, V)));
        dfs(idx+1, ryt(y, x, down(y, x, V)));
        dfs(idx+1, down(y, x, lf(y, x, V)));
        dfs(idx+1, lf(y, x, up(y, x, V)));
    } else if (G[y][x] == 4) {
        dfs(idx+1, lf(y,x, up(y,x, ryt(y,x,V))));
        dfs(idx+1, up(y,x, ryt(y,x, down(y,x,V))));
        dfs(idx+1, lf(y,x, down(y,x, ryt(y,x,V))));
        dfs(idx+1, down(y,x, lf(y,x, up(y,x,V))));
    } else { // == 5
        dfs(idx+1, up(y,x, ryt(y,x, down(y,x, lf(y,x,V)))));
    }
}

void solve() {
    dfs(0, G);
    cout << ans;
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> G[i][j];
            if (0 < G[i][j] && G[i][j] < 6)
                CCTV.push_back({i, j});
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    input(), solve();
}