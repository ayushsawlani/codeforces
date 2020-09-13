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
ll solve(ve <ll> in, ll place)
{
    if(place==-1)
        return 0;
    ll n=sz(in);
    ll x=0;
    fr(i, 0, n-1)
    {
        if((ll)log2(in[i])==place)
            x++;
    }
    if((x==0)||(x==n))
    {
        fr(i, 0, n-1)
            if(place==(ll)log2(in[i]))
                in[i]-=pow(2, place);
        return solve (in, place-1);
    }
    else
    {
        ve <ll> a, b;
        fr(i, 0, n-1)
        {
            if((ll)log2(in[i])==place)
            {
                a.pb(in[i]-pow(2, place));
            }
            else
            {
                b.pb(in[i]);
            }
        }
        return pow(2, place)+min(solve(a, place-1), solve (b, place-1));
    }
}
int main()
{
    fastio
    ll n;
    cin>>n;
    ve <ll> in(n, 0);
    inarr(i, in, n);
    cout<<solve(in, 33)<<endl;
}