#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    while(cin>>n){
        vector<int> v;
        while(n--){
            int num;cin>>num;
            int pos=lower_bound(v.begin(), v.end(), num)-v.begin();
            if(pos==v.size())v.push_back(num);
            else if(v[pos]>num)v[pos]=num;
        }
        cout<<v.size()<<'\n';
    }
    return 0;
}
 
