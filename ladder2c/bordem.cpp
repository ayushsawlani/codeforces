#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 100001
//dp
int main()
{
    ll arr[M]={0};
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        arr[temp]++;
    }
    ll b[M];
    for(ll i=0;i<M;i++)
    {
        b[i]=i*arr[i];
    }
    ll dp[M];
    dp[1]=b[1];
    dp[2]=max(b[1],b[2]);
    for(ll i=3;i<M;i++)
    {
        dp[i]=max(b[i]+dp[i-2],dp[i-1]);
    }
    cout<<dp[M-1]<<endl;

}