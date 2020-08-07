#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n1,n2;
        cin>>n1;
        ll c1[2];
        ll c2[2];
        memset(c1,0,2*sizeof(ll));
        memset(c2,0,2*sizeof(ll));
        for(ll i=0;i<n1;i++)
        {
            ll temp;
            cin>>temp;
            c1[temp%2]++;
        }
        cin>>n2;
        for(ll i=0;i<n2;i++)
        {
            ll temp;
            cin>>temp;
            c2[temp%2]++;
        }
        ll ans=0;
        ans+=c1[0]*c2[0];
        ans+=c1[1]*c2[1];
        cout<<ans<<endl;
    }
}