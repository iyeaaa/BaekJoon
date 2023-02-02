
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> list;
    vector<int> stack;
    vector<int> result = {0};
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        list.push_back(x);
    }
    stack.push_back(0);

    for(int i = 1; i < N; i++) {
        while(!stack.empty() && list[stack.back()] < list[i]) {
            stack.pop_back();
        }
        if(stack.empty()) {
            result.push_back(0);
            stack.push_back(i);
        }
        else {
            result.push_back(stack.back() + 1);
            stack.push_back(i);
        }
    }

    for(int i = 0; i < N; i++) cout << result[i] << ' ';
}