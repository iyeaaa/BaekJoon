#include <bits/stdc++.h>

#define fr(i, l, r) for(int i=l;i<r;i++)
using namespace std;
typedef vector<int> vi;

const int INF = 99999999;
const int dz[] = {-1, 0, 0, 0, 0, 1};
const int dy[] = {0, 1, -1, 0, 0, 0};
const int dx[] = {0, 0, 0, 1, -1, 0};
vector<vi> blueprint[5];
vector<vi> qube[5];
int ans = INF;
int step[5] = {0, 1, 2, 3, 4};

void rotate(int idx) {
    vector<vi> rtn(5, vi(5));
    fr(i, 0, 5) fr(j, 0, 5) rtn[j][4 - i] = qube[idx][i][j];
    qube[idx] = rtn;
}

bool isRange(int z, int y, int x) {
    return z >= 0 && z < 5 && y >= 0 && y < 5 && x >= 0 && x < 5;
}

int minDist() {
    if (qube[0][0][0] == 0)
        return INF;

    int vst[5][5][5];
    queue<tuple<int, int, int>> q;

    memset(vst, -1, sizeof(vst));
    q.push({0, 0, 0});
    vst[0][0][0] = 0;

    while (!q.empty()) {
        auto [z, y, x] = q.front();
        q.pop();
        if (z == 4 && y == 4 && x == 4)
            return vst[z][y][x];
        fr(i, 0, 6) {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (!isRange(nz, ny, nx)) continue;
            if (vst[nz][ny][nx] != -1) continue;
            if (qube[nz][ny][nx] == 0) continue;

            q.push({nz, ny, nx});
            vst[nz][ny][nx] = vst[z][y][x] + 1;
        }
    }

    return INF;
}

// O(5! * 5^4 * 5^2 * 5^3) < 2*10^8
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    fr(i, 0, 5) blueprint[i] = vector(5, vi(5));
    fr(i, 0, 5) fr(j, 0, 5) fr(k, 0, 5) cin >> blueprint[i][j][k];

    do {
        fr(i, 0, 5) qube[i] = blueprint[step[i]];
        fr(_, 0, 4) {
            fr(__, 0, 4) {
                fr(___, 0, 4) {
                    fr(____, 0, 4) {
                        fr(_____, 0, 4) {
                            ans = min(ans, minDist());
                            rotate(4);
                        }
                        rotate(3);
                    }
                    rotate(2);
                }
                rotate(1);
            }
            rotate(0);
        }
    } while (next_permutation(step, step+5));
    

    cout << (ans == INF ? -1 : ans);
}
