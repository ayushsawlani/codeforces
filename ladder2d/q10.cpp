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
#define fr(i, a, b); for (int i = a; i < b; i++)
#define frn(i, a, b); for (int i = a; i > b; i--)
#define mk make_pair
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
int main()
{
    //fastio
    ll l,r;
    cin>>l>>r;
    ll _temp;
    if(l<r)
        swap(l,r,_temp);
    ve <ll> binl, binr;
    while((l>0)||(r>0))
    {
        binl.pb(l%2);
        binr.pb(r%2);
        l/=2;
        r/=2;
    }
    ve <ll> ans(binl.size());
    ll i=binl.size()-1;
    while(binl[i]==binr[i])
    {
        ans[i]=0;
        i--;
    }
    while(i>=0)
    {
        ans[i]=1;
        i--;
    }
    ll a=0;
    fr(i,0,ans.size())
    {
        a+=ans[i]*pow(2,i);
    }
    cout<<a<<endl;
}