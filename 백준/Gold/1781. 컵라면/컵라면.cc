#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pr;

struct cmp {
    bool operator()(pr &a, pr &b) {
        return a.second < b.second;
    }
};

bool compare(const pr &a, const pr &b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<pr> ramen;
    priority_queue<pr, vector<pr>, cmp> pq;

    while(N--) {
        int deadLine, cnt; cin >> deadLine >> cnt;
        ramen.push_back({deadLine, cnt});
    }

    sort(ramen.begin(), ramen.end(), compare);

    ll sum = 0;
    ll start = ramen.back().first;

    for(ll i = start; i >= 1 ; i--) {
        while(!ramen.empty() && ramen.back().first >= i) {
            pq.push(ramen.back());
            ramen.pop_back();
        }
        if(pq.empty()) continue;
        sum += pq.top().second;
        pq.pop();
    }

    cout << sum;

    return 0;
}