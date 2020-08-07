#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        ll n,m;
        cin>>n>>m;
        ll x=0;
        ll ans=0;
        for(ll i=1;i<=10;i++)
        {
            x+=((m*i)%10);
        }
        ll p=(n/m);
        ans+=((p/10)*x);
        for(ll i=1;i<=(p%10);i++)
        {
            ans+=((m*i)%10);
        }
        cout<<ans<<endl;
    }
}