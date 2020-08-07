#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    cin>>n>>m;
    if(m<n)
    {
        cout<<m+1<<endl;
        for(ll i=0;i<=m;i++)
        {
            cout<<m-i<<" "<<i<<endl;
        }
    }
    else
    {
        cout<<n+1<<endl;
        for(ll i=0;i<=n;i++)
        {
            cout<<n-i<<" "<<i<<endl;
        }
        
    }
    
}