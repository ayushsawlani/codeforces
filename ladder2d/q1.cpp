#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M ((ll)1e9+7)
ll dp1[(ll)1e5+4];
    ll dp2[(ll)1e5+4];
        ll dp3[(ll)1e5+4];
            ll dp4[(ll)1e5+4];
int main()
{
    //cin.tie(0);
    //ios::sync_with_stdio(0);
    ll n,k;
    scanf("%lld %lld",&n,&k);
    dp1[0]=1;
    dp2[0]=0;
    for(ll i=1;i<(ll)1e5+4;i++)
    {
        dp1[i]=((dp1[i-1]+dp2[i-1])%M);
        if(i-k+1>0)
            dp2[i]=dp1[i-k]+dp2[i-k];
        else
        {
            dp2[i]=0;
        }
    }
    for(ll i=0;i<(ll)1e5+4;i++)
    {
        dp3[i]=0;dp4[i]=0;
        dp3[i]=(dp2[i]+dp1[i])%M;
        if(i>0)
            dp4[i]=(dp4[i-1]+dp3[i])%M;
        else
        {
            dp4[i]=0;
        }   
    }
    
    for(ll i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        cout<<(dp4[b]-dp4[a-1]+M)%M<<endl;
    }
    return 0;
}