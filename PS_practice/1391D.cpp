#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ceil (ll)ceil
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
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
ll solve2(ve <ve <ll>> in)
{
    ll n=sz(in[0]);
    ve <ll> mo(n, 0);
    ll c1=0;
    fr(i, 0, n-1)
    {
        mo[i]=(in[0][i]+in[1][i])%2;
        if((i%2)&&(mo[i]))
            c1++;
        if((i%2==0)&&(mo[i]==0))
            c1++;
    }
    return min(c1, n-c1);
}
ll bin_to_int(ll a2, ll a1, ll a0)
{
    return a0+a1*2+a2*4;
}
ll solve3(ve <ve <ll>> in)
{
    ll n=sz(in[0]);
    ve <ve <ve <ve <ll>>>> dp(n, ve <ve <ve <ll>>>(2, ve <ve <ll>>(2,ve <ll>(2, 0))));
    fr(i, 0, 1)
    {
        fr(j, 0, 1)
        {
            fr(k, 0, 1)
            {
                if(in[0][0]!=i)
                    dp[0][i][j][k]++;
                if(in[1][0]!=j)
                    dp[0][i][j][k]++;
                if(in[2][0]!=k)
                    dp[0][i][j][k]++;
            }
        }
    }
    fr(i, 1, n-1)
    {
        fr(j, 0, 1)
        {
            fr(k, 0, 1)
            {
                fr(l, 0, 1)
                {
                    dp[i][j][k][l]=min(dp[i-1][j][(k+1)%2][l], dp[i-1][(j+1)%2][k][(l+1)%2]);
                    if(in[0][i]!=j)
                    {
                        dp[i][j][k][l]++;
                    }
                    if(in[1][i]!=k)
                    {

                        dp[i][j][k][l]++;
                    }
                    if(in[2][i]!=l)
                    {
                        dp[i][j][k][l]++;
                    }
                }
            }
        }
    }
    ll ans=inf;
    fr(i, 0, 1)
    {
        fr(j, 0, 1)
        {
            fr(k, 0, 1)
            {
                ans=min(ans, dp[n-1][i][j][k]);
            }
        }
    }
    return ans;
}


int main()
{
    //fastio
    ll n, m;
    cin>>n>>m;
    ve <ve <ll>> in(min(n, m), ve <ll> (max(n,m)));
    fr(i, 0, n-1)
    {
        string te;
        cin>>te;
        fr(j, 0, m-1)
        {
            if(n<m)
                in[i][j]=te[j]-'0';
            else
            {
                in[j][i]=te[j]-'0';
            }
            
        }
    }
    if(n>m)
    {
        ll t;
        swap(n, m, t);
    }
    if(n>=4)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    if(n==2)
    {
        ll ans=solve2(in);
        cout<<ans<<endl;
    }
    if(n==3)
    {
        ll ans1=solve3(in);
        cout<<ans1<<endl;
    }
}