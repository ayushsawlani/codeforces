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
ll solve(ve <ll> in)
{
    ll minele=inf;
    ll n=sz(in);
    if(n==0)
        return 0;
    fr(i, 0, n-1)
    {
        if(minele>in[i])
        {
            minele=in[i];
        }
    }
    ll ans=0;
    fr(i, 0, n-1)
    {
        in[i]-=minele;
    }
    ans=n;
    ve <ll> take;
    ll ans2=minele;
    fr(i, 0, n-1)
    {
        if(in[i]==0)
        {
            ans2+=solve(take);
            take.clear();
        }
        else
        {
            take.pb(in[i]);
        }
    }
    ans2+=solve(take);
    ans=min(ans2, ans);
    //outarr(i, in, n);
    //cout<<endl;
    //cout<<minele<<endl;
    //cout<<ans<<endl;
    return ans;
}
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve <ll> in(n);
    inarr(i, in, n);
    cout<<min(n, solve(in))<<endl;
}