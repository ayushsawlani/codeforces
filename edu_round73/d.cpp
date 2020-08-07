#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[300000][3];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            cin>>b[i];
        }
        dp[0][0]=0;
        dp[0][1]=b[0];
        dp[0][2]=2*b[0];
        ll m1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                m1=INT64_MAX;
                for(int k=0;k<3;k++)
                {
                    if(a[i]+j!=a[i-1]+k)
                    {
                        m1=min(dp[i-1][k],m1);
                    }
                }
                dp[i][j]=m1+b[i]*j;
            }
        }
        ll ans=dp[n-1][0];
        ans=min(ans,dp[n-1][1]);        
        ans=min(ans,dp[n-1][2]);        
        cout<<ans<<endl;
    }
}