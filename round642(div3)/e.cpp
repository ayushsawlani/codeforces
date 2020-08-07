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
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        ve <ve <ll>> dp(n, ve <ll> (2, 0));
        ve <ll> co(n, 0);
        fr(i, 0, n-1)
        {
            if(i>0)
            {
                co[i]=co[i-1];
            }
            if(s[i]=='1')
            {
                co[i]++;
            }
        }
        fr(i, 0, k-1)
        {
            if(i==0)
            {
                if(s[i]=='1')
                {
                    dp[i][0]=1;
                    dp[i][1]=0;
                }
                else
                {
                    dp[i][0]=0;
                    dp[i][1]=1;
                }
                continue;
            }
            dp[i][1]=co[i-1];
            dp[i][0]=min(dp[i-1][0], dp[i-1][1]);
            if(s[i]=='1')
            {
                dp[i][0]++;
            }
            else
            {
                dp[i][1]++;
            }
        }
        fr(i, k, n-1)
        {
            dp[i][1]=min(dp[i-k][1]+co[i-1]-co[i-k], co[i-1]);
            dp[i][0]=min(dp[i-1][1], dp[i-1][0]);
            if(s[i]=='1')
                dp[i][0]++;
            else
            {
                dp[i][1]++;
            }
        }
        cout<<min(dp[n-1][1], dp[n-1][0])<<endl;
    }
}