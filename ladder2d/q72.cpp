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
void printans(pair <ll,ll> seed, ve <ve<ve<pair <ll,ll>>>> &par, ve <ve<ll>>&in, ll rem, ll k)
{
    //cout<<seed.fi<<" "<<seed.se<<" "<<rem<<endl;
    if(par[seed.fi][seed.se][rem]!=mk((ll)-1, (ll)-1))
    {
        printans(par[seed.fi][seed.se][rem], par, in, (rem-in[seed.fi][seed.se]%k+k)%k, k);
        string ans="L";
        if(seed.se>par[seed.fi][seed.se][rem].se)
        {
            ans="R";
        }
        cout<<ans;
    }
    else
    {
        cout<<seed.se+1<<endl;
    }
    
}
int main()
{
    //fastio
    ll n, m, k;
    cin>>n>>m>>k;
    ve <ve <ll>> in(n, ve<ll>(m));
    fr(i,0, n-1)
    {
        string _t;
        cin>>_t;
        fr(j, 0, m-1)
        {
            in[i][j]=_t[j]-'0';
        }
    }
    k++;
    ve <ve<ve<ll>>> dp(n+5, ve<ve<ll>>(m+5, ve <ll>(k, -inf)));
    ve <ve<ve<pair <ll,ll>>>> par(n+5, ve<ve<pair <ll,ll>>>(m+5, ve <pair <ll,ll>>(k, pair <ll,ll>(-1, -1))));
    fr(i, 0, m-1)
    {
        dp[n-1][i][in[n-1][i]%k]=in[n-1][i];
    }
    frn(i, n-2, 0)
    {
        fr(j, 0, m-1)
        {
            fr(rem, 0, k-1)
            {
                dp[i][j][(in[i][j]+rem)%k]=max((j>0?dp[i+1][j-1][rem]:-inf), (j<m-1?dp[i+1][j+1][rem]:-inf));
                if(dp[i][j][(in[i][j]+rem)%k]!=-inf)
                {
                    dp[i][j][(in[i][j]+rem)%k]+=in[i][j];
                }
                if(dp[i][j][(in[i][j]+rem)%k]!=-inf)
                {
                    //cout<<i<<" "<<j<<" "<<(in[i][j]+rem)%k<<endl;
                    par[i][j][(in[i][j]+rem)%k]=mk(i+1, j-1);
                    if((j>0?dp[i+1][j-1][rem]+in[i][j]:-inf)<(j<m-1?dp[i+1][j+1][rem]+in[i][j]:-inf))
                    {
                        par[i][j][(in[i][j]+rem)%k]=mk(i+1, j+1);
                    }
                }
            }
        }
    }
    ll ans1=-inf;
    pair <ll,ll> ans2=mk(-1, -1);
    fr(j, 0, m-1)
    {
        if(ans1<dp[0][j][0])
        {
            ans2=mk(0, j);
            ans1=dp[0][j][0];
        }
    }
    if(ans1==-inf)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans1<<endl;
    printans(ans2, par, in, 0, k);
    cout<<endl;
    //*/
}