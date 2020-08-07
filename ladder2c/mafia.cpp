#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    ll sum=0;
    ll m=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        m=max(m,a[i]);
    }
    ll ans=sum/(n-1);
    if(ans*(n-1)!=sum)
        ans++;
    ans=max(ans, m);
    cout<<ans<<endl;
}