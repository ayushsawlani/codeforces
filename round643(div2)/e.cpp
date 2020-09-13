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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
ll a, r, m;
ll fun(ve <ll> &in, ll a, ll r, ll m, ll h)
{
    ll n=sz(in);
    ll c1=0;
    ll c2=0;
    fr(i, 0, n-1)
    {
        c1+=max((h-in[i]), (ll)0);
        c2+=max((in[i]-h), (ll)0);
    }
    ll ans=min(c1, c2)*m+(c1-min(c1, c2))*a+(c2-min(c1, c2))*r;
    return ans;
}
ll solve(ve <ll> &in, ll left, ll right)
{
    ll i=left;
    ll j=right;
    while(j-i>2)
    {
        ll mid=(i+j)/2;
        ll val1=fun(in, a, r, m, mid-1);
        ll val2=fun(in, a, r, m, mid);
        ll val3=fun(in, a, r, m, mid+1);
        if((val1>=val2)&&(val3>=val2))
        {
            return val2;
        }
        else if(val1>=val2)
        {
            i=mid+1;
        }
        else
        {
            j=mid-1;
        }
    }
    ll ans=inf;
    fr(k, i, j)
    {
        ans=min(fun(in, a, r, m, k), ans);
    }
    return ans;
}
int main()
{
    //fastio
    ll n;
    cin>>n>>a>>r>>m;
    if(a+r<m)
    {
        m=a+r;
    }
    ve <ll> in(n);
    inarr(i, in, n);
    cout<<solve(in, 0, 1e9)<<endl;
}