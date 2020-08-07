#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main()
{
    ll n,m;
    cin>>n>>m;
    string s[n];
    for(ll i=0;i<n;i++)
    {
        cin>>s[i];
    }
    ll ans=1;
    for(ll j=0;j<m;j++)
    {
        ll flag[26]={0};
        for(ll i=0;i<n;i++)
        {
            flag[(ll)s[i][j]-65]++;
        }
        ll c=0;
        for(ll i=0;i<26;i++)
            if(flag[i])
                c++;
        ans=(ans*(c%M))%M;
    }
    cout<<ans<<endl;
}