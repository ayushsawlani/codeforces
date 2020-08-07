#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll ans=0;
    ll c_minus1=0,c_zero=0;
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        if(temp<0)
            c_minus1++;
        else if(temp==0)
            c_zero++;
        if(temp<0)
            temp=(-1)*(temp);
        if(temp!=0)
            ans+=(temp-1);
    }
    ans+=c_zero;
    if(c_zero==0)
    {
        if(c_minus1%2!=0)
            ans+=2;
    }
    cout<<ans<<endl;
}