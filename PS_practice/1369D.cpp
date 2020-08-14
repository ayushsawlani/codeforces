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
const ll siz=2*1e6+5;

int main()
{
    ve <ll> ans0(siz, 0);
    ve <ll> ans1(siz, 0);
    ve <ll> ans(siz, 0);
    //fastio
    ans0[3]=4;
    ans1[3]=0;
    ans[3]=4;
    fr(i, 4, siz-1)
    {
        ans1[i]=2*ans[i-2]+ans[i-1];
        ans0[i]=4+2*ans1[i-2]+ans1[i-1];
        ans0[i]%=mod;
        ans1[i]%=mod;
        ans[i]=max(ans0[i], ans1[i]);
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll q;
        cin>>q;
        cout<<ans[q]<<endl;
    }
}