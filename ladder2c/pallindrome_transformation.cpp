#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,p;
    cin>>n>>p;
    p--;
    ll ans=0;
    string s;
    cin>>s;
    if(p>=(s.size()/2))
    {
        p=n-p-1;
    }
    ll first=p,last=p;
    for(ll i=p;i>=0;i--)
    {
        if(s[i]!=s[n-1-i])
        {
            ll x=s[i]-s[n-1-i];
            if(x<0)
                x=(-1)*x;
            x=min(x,26-x);
            ans+=x;
            first=i;
        }
    }
    for(ll i=p+1;i<s.size()/2;i++)
    {
        if(s[i]!=s[n-1-i])
        {
            ll x=s[i]-s[n-1-i];
            if(x<0)
                x=(-1)*x;
            x=min(x,26-x);
            ans+=x;
            last=i;
        }
    }
    ll m1=min(p-first,last-p);
    ll m2=max(p-first,last-p);
    ans+=(2*m1+m2);
    cout<<ans<<endl;
}