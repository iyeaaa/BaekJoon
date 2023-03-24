#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, k;
int g[20][20];
int dice[7]; // 위, 아래, 동, 서, 남, 북
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

bool OOB(int r, int c) {
    return r < 0 || r >= n || c < 0 || c >= m;
}

void tumble(int dir) {
    int t[7]; // 위, 아래, 동, 서, 남, 북

    switch (dir) {
        case 1: // 동
            t[3] = dice[1], t[4] = dice[2], t[2] = dice[3];
            t[1] = dice[4], t[5] = dice[5], t[6] = dice[6];
            break;
        case 2: // 서
            t[4] = dice[1], t[3] = dice[2], t[1] = dice[3];
            t[2] = dice[4], t[5] = dice[5], t[6] = dice[6];
            break;
        case 3: // 남
            t[5] = dice[1], t[6] = dice[2], t[3] = dice[3];
            t[4] = dice[4], t[2] = dice[5], t[1] = dice[6];
            break;
        default: // 북
            t[6] = dice[1], t[5] = dice[2], t[3] = dice[3];
            t[4] = dice[4], t[1] = dice[5], t[2] = dice[6];
    }

    for (int i = 1; i <= 6; i++)
        dice[i] = t[i];
}

int main() {
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    for (int i = 0; i < k; i++) {
        int dir;
        cin >> dir;

        if (OOB(x + dx[dir], y + dy[dir]))
            continue;

        tumble(dir);
        x += dx[dir];
        y += dy[dir];

        if (g[x][y] == 0)
            g[x][y] = dice[2];
        else
            dice[2] = g[x][y], g[x][y] = 0;

        cout << dice[1] << '\n';
    }
}