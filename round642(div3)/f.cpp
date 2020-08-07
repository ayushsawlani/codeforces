#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define pb push_back
#define mod 1000000007
#define inarr(i,arr,n); for(ll i=0;i<n;i++) cin >> arr[i];
#define outarr(i,arr,n); for(ll i=0;i<n;i++) cout<<arr[i]<<' ';
#define swap(a,b,t) {t=a;a=b;b=t;}
#define ve vector
#define sz(a) (int)((a).size())
#define fi first
#define se second
#define pa pair
#define fastio  {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define ll long long int
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e17;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, m;
        cin>>n>>m;
        ve <ve <ll>> in(n, ve <ll> (m));
        fr(i, 0, n-1)
        {
            inarr(j, in[i], m);
        }
        ve <ll> posh;
        fr(i, 0, n-1)
        {
            fr(j, 0, m-1)
            {
                posh.pb(in[i][j]-i-j);
            }
        }
        ll ans=inf;
        fr(i, 0, sz(posh)-1)
        {
            ve <ve <ll>> dp(n, ve <ll> (m, inf));
            if(in[0][0]>=posh[i])
                dp[0][0]=in[0][0]-posh[i];
            fr(j, 0, n-1)
            {
                fr(k, 0, m-1)
                {
                    ll proh=posh[i]+j+k;
                    if((proh<=in[j][k])&&((j!=0)||(k!=0)))
                    {
                        dp[j][k]=in[j][k]-proh+min(j>0?dp[j-1][k]:inf, k>0?dp[j][k-1]:inf);
                    }
                }
            }
            if(dp[n-1][m-1]<inf)
            {
                ans=min(ans, dp[n-1][m-1]);
            }
        }
        cout<<ans<<endl;
    }
}