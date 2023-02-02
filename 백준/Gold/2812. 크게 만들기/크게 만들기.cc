
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    vector<int> stk;
    int N, K, x;

    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        scanf("%1d", &x);
        while (!stk.empty() && K > 0 && stk.back() < x) {
            stk.pop_back();
            K--;
        }
        stk.push_back(x);
    }

    for (int i = 0; i < stk.size()-K; i++) printf("%d", stk[i]);
}