#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ceil (ll)ceil
#define ll int
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
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
ll gcd(ll a, ll b)
{
    if(a%b==0)
        return b;
    else
    {
        return gcd(b, a%b);
    }
}
ve <ll> factorize(ll n)
{
    ve <ll> ans;
    fr(i, 2, sqrt(n))
    {
        if(n%i==0)
        {
            n=n/i;
            ans.pb(i);
            i--;
        }
    }
    if(n>1)
        ans.pb(n);
    return ans;
}
int main()
{
    //fastio
    ll n, m;
    cin>>n>>m;
    ve <ll> a(n);
    inarr(I, a, n);
    set <ll> b;
    fr(i, 0, m-1)
    {
        ll _t;
        cin>>_t;
        b.insert(_t);
    }
    ve <ll> cumgcd(n);
    cumgcd[0]=a[0];
    fr(i, 1, n-1)
    {
        cumgcd[i]=gcd(cumgcd[i-1], a[i]);
       // cout<<cumgcd[i]<<endl;
    }
    //cout<<yess<<endl;
    ve <ve <ll>> cumfac(n);
    ll x=a[0];
    ll ans=0;
    fr(i, 0, n-1)
    {
        ve <ll> util=factorize(a[i]);
        for(auto j:util)
        {
            if(b.find(j)==b.end())
            {
                ans++;
            }
            else
            {
                ans--;
                /* code */
            }
            
        }
    }
    for(int i=2;(i<=sqrt(x))&&(x);i++)
    {
        if(x%i==0)
        {
            x=x/i;
            cumfac[0].pb(i);
           i--;
        }
    }
    if(x>1)
    {
        cumfac[0].pb(x);
    }
   //outarr(i, cumfac[0], sz(cumfac[0]));
   //cout<<endl;
        //cout<<ans<<endl;
    fr(i, 1, n-1)
    {
        ll x=cumgcd[i];
        for(auto j: cumfac[i-1])
        {
            if(x==0)
                break;
            if(x%j==0)
            {
                x=x/j;
                cumfac[i].pb(j);
            }
        }
    }
    ll alr=0;
    frn(i, n-1, 0)
    {
        ll num=0;
        for(auto j:cumfac[i])
        {
            if(b.find(j)==b.end())
            {
                num++;
            }
            else 
                num--;
        }
        num=(-num);
        if(num>alr)
        {
            ans+=((num-alr)*(i+1));
            alr=num;
        }
    }
    cout<<ans<<endl;
}