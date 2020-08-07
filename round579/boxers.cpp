#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll ans=0;
    ll n;
    cin>>n;
    ll d[n];
    for(ll i=0;i<n;i++)
    {
        cin>>d[i];
    }
    vector <pair <ll,ll>> v;
    sort(d,d+n);
    
    ll a[150002],b[150002];
    for(ll i=0;i<150002;i++)
    {
        a[i]=0;
        b[i]=0;
    }
    for(ll i=0;i<n;i++)
    {
        b[d[i]]++;
        a[d[i]]++;
    }
    for(ll i=1;i<150002;i++)
    {
        if((a[i]>1)||(b[i]>1))
        {
            b[i]--;
            b[i+1]++;
            a[i]--;
        }
    }
    for(ll i=150001;i>1;i--)
    {
        if((a[i]>1)||(b[i]>1))
        {
            b[i]--;
            b[i-1]++;
            a[i]--;
        }
    }
    for(ll i=1;i<150002;i++)
    {
        if(b[i]>0)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    
}