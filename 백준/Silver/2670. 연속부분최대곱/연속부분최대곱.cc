#include <cstdio>
#include <algorithm>
using namespace std;

int n;
double arr[10001];
double ans = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lf", &arr[i]);

    ans = arr[1];

    for (int i = 2; i <= n; ++i) {
        if (arr[i] * arr[i - 1] >= arr[i]) {
            arr[i] = arr[i - 1] * arr[i];
        }
        ans = max(ans, arr[i]);
    }

    printf("%.3lf", ans);
    return 0;
}