#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,x,y;
    cin>>n>>m>>x>>y;
    ll a[n][m]={0};
    ll cost[1001][2]={0};
    for(ll i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(ll j=0;j<m;j++)
        {
            if(s[j]=='#')
            {
                a[i][j]=1;
            }
        }
    }
    for(ll i=0;i<m;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(a[j][i]==1)
            {
                cost[i][1]++;
            }
            else
            {
                cost[i][0]++;
            }
        }
        cost[i][0]=n-cost[i][0];
        cost[i][1]=n-cost[i][1];

    }
    ll dp[1001][1001][2]={INT32_MAX};
    for(ll i=0;i<=1000;i++)
    {
        for(ll j=0;j<=1000;j++)
        {
            dp[i][j][0]=INT32_MAX;
            dp[i][j][1]=INT32_MAX;
        }
    }
    dp[0][0][0]=0;
    dp[0][0][1]=0;
    for(ll i=1;i<=x;i++)
    {
        dp[i][i][0]=dp[i-1][i-1][0]+cost[i-1][0];
        dp[i][i][1]=dp[i-1][i-1][1]+cost[i-1][1];
    }
    for(ll i=x+1;i<=1000;i++)
    {
        for(ll j=1;j<=i;j++)
        {
            if(j==1)
            {
                ll c1=INT32_MAX,c2=INT32_MAX;
                for(ll k=x;k<=min(i-1,y);k++)
                {
                    c1=min(dp[i-1][k][0],c1);
                    c2=min(dp[i-1][k][1],c2);
                }
                dp[i][1][0]=c2+cost[i-1][0];
                dp[i][1][1]=c1+cost[i-1][1];
            }
            else
            {
                dp[i][j][0]=dp[i-1][j-1][0]+cost[i-1][0];
                dp[i][j][1]=dp[i-1][j-1][1]+cost[i-1][1];
            }
        }
    }
    ll ans=INT32_MAX;
    for(ll i=x;i<=min(m,y);i++)
    {
        ans=min(ans,dp[m][i][0]);
        ans=min(ans,dp[m][i][1]);   
    }
    cout<<ans<<endl;
    //fdsf

}