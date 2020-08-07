#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main()
{
 cin.tie(0);
ios::sync_with_stdio(0);
    ll m;
    cin>>m;
    ll dis[m];
    for(ll i=0;i<m;i++)
    {
        cin>>dis[i];
    }
    sort(dis,dis+m);
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    ll ans=0;
    ll i=n-1;
    while(i>=0)
    {
        ll c=0;
        while((c<dis[0])&&(i>=0))
        {
            ans+=a[i];
            i--;
            c++;
        }
        i-=2;
    }
    cout<<ans<<endl;
}