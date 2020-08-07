#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll gcd(ll a,ll b)
{
    if(a%b==0)
        return b;
    else
    {
        return gcd(b,a%b);
    }
}
int main()
{
    ll n;
    double x0,y0;
    cin>>n>>x0>>y0;
    set <pair<ll,ll>> s;
    ll ans=0;
    ll t=0;//hello
    for(ll i=0;i<n;i++)
    {
        double x,y,m;
        cin>>x>>y;
        if(x0!=x)
        {
            ll g=gcd(y0-y,x0-x);
            ll a=(y0-y)/g;
            ll b=(x0-x)/g;
            pair <ll,ll> p;
            p.first=a;
            p.second=b;
            auto it=s.find(p);
            if(it==s.end())
            {
                s.insert(p);
                ans++;
            }
        }
        else 
            t++;
    }
    if(t)
        ans++;
    cout<<ans<<endl;
}