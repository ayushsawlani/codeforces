#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    cin>>n>>m;
    string ans[n];
    for(ll i=0;i<n;i++)
    {
        cin>>ans[i];
    }
    ll max_count[m];
    for(ll i=0;i<m;i++)
    {
        max_count[i]=0;
        ll c[26]={0};
        for(ll j=0;j<n;j++)
        {
            c[ans[j][i]-'A']++;
        }
        for(ll j=0;j<26;i++)
        {
            max_count[i]=max(max_count[i],c[j]);
        }
    }
    ll ans=0;
    for(ll i=0;i<m;i++)
    {
        ll temp;
        cin>>temp;
        ans=ans+(temp*max_count[i]);
    }
    cout<<ans<<endl;
}