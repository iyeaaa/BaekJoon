
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int N, L;
int A[5000001];
deque<int> dq;
vector<int> result = {0};

void Print() {
    for(int i = 1; i <= N; i++) {
        cout << result[i] << " ";
    }
}

void Solve() {
    for(int i = 1; i <= L; i++) {
        while(!dq.empty() && dq.back() > A[i])
            dq.pop_back();
        dq.push_back(A[i]);
        result.push_back(dq.front());
    }

    for(int i = L+1; i <= N; i++) {
        if(dq.front() == A[i-L])
            dq.pop_front();
        while(!dq.empty() && dq.back() > A[i])
            dq.pop_back();
        dq.push_back(A[i]);
        result.push_back(dq.front());
    }
}

void Input() {
    cin >> N >> L;
    for(int i = 1; i <= N; i++) {
        int x; cin >> x; A[i] = x;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // deque.front == MIN, and dq == Ascending
    Input();
    Solve();
    Print();
}