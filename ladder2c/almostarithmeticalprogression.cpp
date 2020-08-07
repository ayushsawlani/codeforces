#include <bits/stdc++.h>
using namespace std;
#define ll long int
#define M 1000000007
#define Size 1000010
unordered_map <ll,int> dp[4000];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int ans=1;
    int n;
    cin>>n;
    ll b[n];
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(dp[i].find(b[j])!=dp[i].end())
            {
                if(dp[j].find(b[i])==dp[j].end())
                    dp[j][b[i]]=dp[i][b[j]]+1;
                else
                    dp[j][b[i]]=max(dp[j][b[i]],dp[i][b[j]]+1);
            }
            else
                dp[j][b[i]]=2;
            ans=max(ans,dp[j][b[i]]);
        }
    }
    cout<<ans<<endl;
}