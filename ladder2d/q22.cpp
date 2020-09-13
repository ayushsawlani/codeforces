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
ll count(ll x)
{
    return ((x)*(x+1))/2;
}
int main()
{
    //fastio
    ll r,g;
    cin>>r>>g;
    ll _g=g;
    ll _temp;
    ll number;
    if(r<g)
        swap(r,g,_temp);
    ll h;
    fr(i,1,1e4)
    {
        if(((i)*(i+1))/2<=r+g)
        {
            number=((i)*(i+1))/2;
            h=i;
        }
    }
    ve <ll> dp1(r+5,0);
    ve <ll> dp2(r+5,0);
    dp1[0]=1;
    ll taken_h=1;
    fr(i,1,h+1)
    {
        fr(j,taken_h,min(count(taken_h),r)+1)
        {
            dp2[j]+=dp1[j-taken_h];
            dp2[j]%=mod;
        }
        fr(j,max(count(taken_h)-g,(ll)0),min(count(taken_h),r)+1)
        {
            dp2[j]+=dp1[j];
            dp2[j]%=mod;
        }
        fr(j,0,r+5)
        {
            dp1[j]=dp2[j];
            dp2[j]=0;
        }
        taken_h++;
    }
    ll ans=0;
    fr(i,0,r+1)
    {
        ans+=dp1[i];
        ans%=mod;
    }
    cout<<ans<<endl;
}