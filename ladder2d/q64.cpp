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
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
ll bin(ve <pair <ll,ll>> &in, ll r, ll x)
{
    ll i=0;
    ll j=r;
    while(i<j)
    {
        ll mid=(i+j+1)/2;
        if(in[mid].fi>=x)
        {
            j=mid-1;
        }
        else
        {
            i=mid;
        }
    }
    if(in[i].fi<x)
        return i;
    return -1;
}
int main()
{
    //fastio
    ll n, m;
    cin>>n>>m;
    ve <pair <ll,ll>> in(m);
    ve <ll> dp(m, 0), pre(m, 0);
    fr(i, 0, m-1)
    {
        cin>>in[i].se>>in[i].fi;
    }
    sort(all(in));
    /*fr(i, 0, m-1)
    {
        cout<<in[i].fi<<" "<<in[i].se<<endl;
    }*///
    if(m==0)
    {
        cout<<0<<endl;
        return 0;
    }
    ll i=0;
    while((in[i].se!=0)&&(i<m))
    {
        i++;
    }
    if(i==m)
    {
        cout<<0<<endl;
        return 0;
    }
    ll ans=0;
    dp[i]=1;
    pre[i]=1;
    if(in[i].fi==n)
    {
        ans+=dp[i];
    }
    i++;
    while(i<m)
    {
        ll lol=bin(in, i, in[i].se);
        ll lol2=bin(in, i, in[i].fi);
        //cout<<lol2<<" "<<lol<<endl;
        dp[i]=(lol2>=0?pre[lol2]:0)-(lol>=0?pre[lol]:0);
        dp[i]+=mod;
        dp[i]%=mod;
        if(in[i].se==0)
        {
            dp[i]++;
        }
        dp[i]%=mod;
        pre[i]=pre[i-1]+dp[i];
        pre[i]%=mod;
        if(in[i].fi==n)
            ans+=dp[i];
        ans%=mod;
        i++;
    }
    cout<<ans<<endl;
}