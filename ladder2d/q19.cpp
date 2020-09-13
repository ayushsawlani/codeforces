#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mod 1000000007
#define inarr(i,arr,n); for(ll i=1;i<=n;i++) cin >> arr[i];
#define outarr(i,arr,n); for(ll i=0;i<n;i++) cout<<arr[i]<<' ';
#define swap(a,b,t) {t=a;a=b;b=t;}
#define ve vector
#define sz(a) (int)((a).size())
#define fi first
#define se second
#define pa pair
#define fastio  {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define ll long long int
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve <ll> in(n+1);
    inarr(i,in,n);
    ll dp[n+1];
    dp[1]=2;
    fr(i,2,n+1)
    {
        ll sum=2;
        fr(j,in[i],i)
        {
            sum+=dp[j];
            sum%=mod;
        }
        dp[i]=sum;
    }
    ll ans=0;
    fr(i,1,n+1)
    {
        ans+=dp[i];
        ans%=mod;
    }
    cout<<ans<<endl;
}