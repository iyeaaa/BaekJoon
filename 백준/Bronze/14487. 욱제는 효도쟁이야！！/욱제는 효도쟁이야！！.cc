
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, sum = 0;
    vector<int> cost(50001);

    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &cost[i]);

    sort(cost.begin(), cost.begin()+n);

    for(int i = 0; i < n-1; i++)
        sum += cost[i];

    printf("%d", sum);
}
