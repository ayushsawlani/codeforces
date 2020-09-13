#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ceil (ll)ceil
#define ll long long int
#define pb push_back
#define mod 998244353
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
int main()
{
    //fastio
    ll n,m;
    cin>>n>>m;
    ve <ll> a(n);
    inarr(i, a, n);
    ve <ll> b(m);
    inarr(i, b, m);
    ll ans=1;
    ll j=m-1;
    ll m1=inf;
    ll way=0;
    frn(i, n-1, 0)
    {
        m1=min(a[i], m1);
        if(m1==b[j])
        {
            way++;
        }
        else if(m1<b[j])
        {
            ans=ans*way;
            ans%=mod;
            way=0;
            j--;
            i++;
        }
    }
    if(m1>b[0])
    {
        cout<<0<<endl;
        return 0;
    }
    if(j!=0)
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<ans<<endl;
}