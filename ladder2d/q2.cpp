#include <bits/stdc++.h>
using namespace std;
#define M (1e9+7)
#define ll long long
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n;
    cin>>n;
    ll a[n];
    ll p[5];
    ll ans[5];
    memset(ans,0,5*sizeof(ll));
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(ll i=0;i<5;i++)
    {
        cin>>p[i];
    }
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        sum+=a[i];
        for(ll i=4;i>=0;i--)
        {
            ll x;
            x=sum/p[i];
            ans[i]+=x;
            sum-=x*p[i];
        }
    }
    for(ll i=0;i<5;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<<sum<<endl;
}