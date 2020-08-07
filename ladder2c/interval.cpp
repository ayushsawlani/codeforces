#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
ll getdigits(ll n)
{
    ll ans=0;
    while(n>0)
    {
        n=n/10;
        ans++;
    }
    return ans;
}
ll extractmiddle(ll n)
{
    n=n/10;
    ll x=1;
    ll ans=0;
    while(n/10>0)
    {
        ans+=(n%10)*x;
        n=n/10;
        x*=10;
    }
    return ans;
}
ll first(ll n)
{
    while(n/10>0)
    {
        n=n/10;
    }
    return n;
}
ll getways(ll digits)
{
    if(digits>1)
    {
        return pow(10,digits-2);
    }
    else if(digits==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll l,r;
    cin>>l>>r;
    ll low=getdigits(l);
    ll high=getdigits(r);
    //cout<<high<<" "<<low<<endl;
    ll ans=0;
    for(ll i=low;i<=high;i++)
    {
            ans+=getways(i);
    }
    ans*=9;
    //cout<<ans<<endl;
    ll firsthigh=first(r);
    ll firstlow=first(l);
    ans-=(firstlow-1)*getways(low);
    //cout<<ans<<endl;
    ans=ans-(9-firsthigh)*getways(high);
  //  cout<<ans<<endl;
    if(firstlow<=l%10)
    {
        ans-=max((extractmiddle(l)),(ll)0);
        if(firstlow<l%10)
            ans-=1;
    }
    else if(firstlow>l%10)
    {
        ans-=extractmiddle(l);
    }
    //cout<<ans<<endl;
    if(firsthigh>=r%10)
    {
        ans-=max((getways(high)-extractmiddle(r)-1),(ll)0);
        if(firsthigh>r%10)
            ans-=1;
    }
    else if(firsthigh<r%10)
    {
        ans-=max((getways(high)-extractmiddle(r)-1),(ll)0);
    }
    //cout<<firsthigh<<" "<<firstlow<<endl;
    cout<<ans<<endl;
}