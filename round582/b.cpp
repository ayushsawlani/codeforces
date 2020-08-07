#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    for(ll q=0;q<t;q++)
    {
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll i=n-2;
    ll m=a[n-1];
    ll ans=0;
    while(i>=0)
    {
        if(a[i]>m)
            ans++;
        if(m>a[i])
            m=a[i];
        i--;
    }
    cout<<ans<<endl;
    }
}