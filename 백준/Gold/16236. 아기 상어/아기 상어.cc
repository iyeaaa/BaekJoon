

#include <cstdio>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int n, eat, ans, body = 2;
int a[20][20];
bool check[20][20];
priority_queue<tuple<int, int, int>> q;
const int dx[] = { -1, 0, 0, 1 }, dy[] = { 0, -1, 1, 0 };

void bfs() {
    while (!q.empty()) {
        auto t = q.top(); q.pop();
        int d = -get<0>(t), x = -get<1>(t), y = -get<2>(t);
        if (0 < a[x][y] && a[x][y] < body) {
            eat++;
            if (eat == body) {
                body++;
                eat = 0;
            }
            a[x][y] = 0;
            ans += d;
            d = 0;
            memset(check, false, sizeof(check));
            while (!q.empty()) q.pop();
        }
        for (int i = 0; i<4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (check[nx][ny]) continue;
            if (a[nx][ny] > body) continue;
            q.push(make_tuple(-d - 1, -nx, -ny));
            check[nx][ny] = true;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 9) {
                q.push({ 0, -i, -j });
                a[i][j] = 0;
            }
        }
    }
    bfs();
    printf("%d\n", ans);
    return 0;
}