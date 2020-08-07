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
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve <ll> in(n+1);
    ve <ll> sum(n+1);
    fr(i,1,n+1)
        cin>>in[i];
    sum[0]=0;
    fr(i,1,n+1)
    {
        sum[i]=sum[i-1]+in[i];
    }
    map <ll,ll> m;
    ve <ll> occ(n+1,n+1);
    ll ans=0;
    frn(i,n,0)
    {
        m[sum[i]]=i;
        if(m.find(sum[i-1])!=m.end())
        {
            occ[i]=min(i<n?occ[i+1]:n+1,m[sum[i-1]]);
        }
        else
        {
            occ[i]=i<n?occ[i+1]:n+1;
        }
        ans+=occ[i]-i;
    }
    cout<<ans<<endl;
}