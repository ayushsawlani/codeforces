#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s[n];
        for(ll i=0;i<n;i++)
        {
            cin>>s[i];
        }
        ll ans=0;
        ll x=0,y=0;
        for(ll i=0;i<n;i++)
        {
            ll one_count=0;
            ll zero_count=0;
            for(ll j=0;j<s[i].size();j++)
            {
                if(s[i][j]=='1')
                    one_count++;
                else
                {
                    zero_count++;
                }
            }
            if((one_count%2==1)&&(zero_count%2==1))
            {
                x++;
            }
            else
            {
                ans++;
            }
            if((one_count%2==1)^(zero_count%2==1))
            {
                y++;
            }
        }
        ans+=min(x,y);
        x-=y;
        if(x>0)
            ans+=(x/2)*2;
        cout<<ans<<endl;
    }
}