#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll left=-1;
        for(ll i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                left=i;
                break;
            }
        }
        ll right=n;
        for(ll i=n-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                right=i;
                break;
            }
        }
        if(right==n)
            cout<<n<<endl;
        else if(right==left)
        {
            ll ans=n+1;
            ans=max(ans,2*(n-1-right+1));
            ans=max(ans,2*(left-0+1));
            cout<<ans<<endl;
        }
        else
        {
            ll ans=n+2;
            ans=max(ans,2*(n-1-left+1));
            ans=max(ans,2*(right-0+1));
            ans=max(ans,left-0+1+2*(right-left+1)-1);
            ans=max(ans,n-1-right+1+2*(right-left+1)-1);
            cout<<ans<<endl;
        }
        
    }
}