#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n,v;
    unordered_map<int, int> m;
    
    cin >> n;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        m[x]++;
    }
    
    cin >> v;
    cout << m[v];
}