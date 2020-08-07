#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector <ll> ans;
    for(ll i=0;i<k;i++)
    {
        ans.push_back(1);
    }
    ans.push_back(n);
    ll x=k-1;
    for(ll i=0;i<k-1;i++)
    {
        ans.push_back(n+1);
    }
    if(n==m)
    {
        if(k==1)
            ans.push_back(2*n-1);
        else if(n>2)
        {
            ans.push_back(2*n);   
        }
        if(n<=2)
            ans.push_back(2*n);
    }
    else if(n==m+1)
    {
        if(k==1)
            ans.push_back(n+1);
    }
    cout<<ans.size()<<endl;
    for(ll i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}