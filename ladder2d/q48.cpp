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
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
int main()
{
    //fastio
    ll n, h;
    cin>>n>>h;
    ve <ve <ll>> dp(n+5, ve <ll> (n+5, 0));
    dp[0][0]=1;
    fr(i, 1, n)
    {
        fr(j, 1, n)
        {
            fr(k, 0, i-1)
            {
                ll x=i-1-k;
                fr(l, 0, j-2)
                {
                    dp[i][j]+=dp[k][j-1]*dp[x][l];
                    dp[i][j]+=dp[x][j-1]*dp[k][l];
                }
                dp[i][j]+=dp[k][j-1]*dp[x][j-1];
            }        
        }
    }
    ll ans=0;
    frn(i, n, h)
        ans+=dp[n][i];
    cout<<ans<<endl;
}