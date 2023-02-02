#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int n;
int v[100001];
int ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    for(int i=1; i<=n; i++){
        if(v[i+1]>v[i+2]){
            int a=min(v[i], v[i+1]-v[i+2]);
            ans+=5*a;
            v[i]-=a; v[i+1]-=a;

            int b=min(v[i], min(v[i+1], v[i+2]));
            ans+=7*b;
            v[i]-=b; v[i+1]-=b; v[i+2]-=b;
        }
        else{
            int b=min(v[i], min(v[i+1], v[i+2]));
            ans+=7*b;
            v[i]-=b; v[i+1]-=b; v[i+2]-=b;

            int a=min(v[i], v[i+1]);
            ans+=5*a;
            v[i]-=a; v[i+1]-=a;
        }
        ans+=3*v[i];
    }
    cout << ans << "\n";
    return 0;
}