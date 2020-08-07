#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,l,r,ql,qr;
    cin>>n>>l>>r>>ql>>qr;
    ll w[n];
    for(ll i=0;i<n;i++)
    {
        cin>>w[i];
    }
    ll ans1=0;
    for(ll i=0;i<=((n-1)/2);i++)
        ans1+=(w[i]*l);
    for(ll i=((n-1)/2)+1;i<n;i++)
    {
        ans1+=(w[i]*r);
    }
    ll x=ans1;
    for(ll j=(n-1)/2+1;j<n;j++)
    {
        x+=(l*w[j]-r*w[j]);
        ans1=min(ans1,x+(2*j-n+1)*ql);
    }
    ll ans2=0;
    for(ll i=0;i<=(n)/2-1;i++)
        ans2+=(w[i]*l);
    for(ll i=(n/2);i<n;i++)
    {
        ans2+=(w[i]*r);
    }
    x=ans2;
    for(ll j=(n/2)-1;j>=0;j--)
    {
        x-=w[j]*l;
        x+=w[j]*r;
        ans2=min(ans2,x+(n-2*j-1)*qr);
    }
    cout<<(min(ans2,ans1))<<endl;

}