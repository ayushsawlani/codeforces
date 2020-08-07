#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll ans=0;
    ll cum_xor[n+1];
    cum_xor[0]=0;
    for(ll i=1;i<=n;i++)
    {
        cum_xor[i]=(cum_xor[i-1]^i);
    }
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        ans=(ans^temp);
    }
    for(ll i=1;i<=n;i++)
    {
        ll x;
        if((n/i)%2==0)
        {
            x=(cum_xor[(n%i)]);
        }
        else
        {
            x=(cum_xor[i-1]^cum_xor[n%i]);
        }
        ans=ans^x;
    }
    cout<<ans<<endl;
}