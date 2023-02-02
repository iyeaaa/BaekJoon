
#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    set<pair<int, int>> problem;
    map<int, int> dict;

    for(int i = 0; i < N; i++) {
        int P, L; cin >> P >> L;
        problem.insert({L, P});
        dict[P] = L;
    }

    int M; cin >> M;

    for(int i = 0; i < M; i++) {
        string cmd; cin >> cmd;
        if(cmd == "add") {
            int P, L; cin >> P >> L;
            problem.insert({L, P});
            dict[P] = L;
        } else if(cmd == "recommend") {
            int x; cin >> x;
            if(x == -1)
                cout << (*problem.begin()).second << "\n";
            else
                cout << (*prev(problem.end())).second << "\n";
        } else {
            int p; cin >> p;
            problem.erase({dict[p], p});
            dict.erase(p);
        }
    }
}