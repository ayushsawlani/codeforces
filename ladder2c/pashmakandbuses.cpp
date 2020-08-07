#include <bits/stdc++.h>
using namespace std;
#define ll long long
void next(vector <ll>&input,ll i,ll k)
{
    if(input[i]==k)
    {
        input[i]=1;
        next(input,i-1,k);
    }
    else if(i>=0)
    {
        input[i]++;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,k,d;
    cin>>n>>k>>d;
    ll x=k;
    ll flag=0;
    for(ll i=1;i<=d;i++)
    {
        if(n<=x)
        {
            flag=1;
            break;
        }
        x=x*k;
    }
    if(flag==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    vector <ll> v;
    for(ll i=0;i<d;i++)
        v.push_back(1);
    ll ans[d][n];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<d;j++)
        {
            ans[j][i]=v[j];
        }
        next(v,d-1,k);
    }
    for(ll i=0;i<d;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }   
}