
#include <iostream>
#include <queue>

using namespace std;

struct comp {
    bool operator()(int a, int b) {
        return abs(a) != abs(b) ? abs(a) > abs(b) : a > b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    priority_queue<int, vector<int>, comp> q;

    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        if(x != 0) {
            q.push(x);
        } else {
            if(q.empty()) {
                cout << 0 << '\n';
            } else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
    }
}