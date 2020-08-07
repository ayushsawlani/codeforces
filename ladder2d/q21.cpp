#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
int main()
{
    //fastio
    ll n,m;
    cin>>n>>m;
    ve <ll> in(n);
    fr(i,0,n)
    {
        double x;
        cin>>in[i]>>x;
    }
    ve <ll> dp(n,1);
    ll m1=1;
    fr(i,1,n)
    {
        frn(j,i-1,-1)
        {
            if(in[i]>=in[j])
            {
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        m1=max(m1,dp[i]);
    }
    cout<<n-m1<<endl;
}