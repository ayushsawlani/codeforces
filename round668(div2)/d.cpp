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
void dfs(ve <ve <ll>> &G, ve <ll> &c, ve <ll> &dist, ve <ll> &pi, ll seed)
{
    c[seed]=1;
    for(auto chi:G[seed])
    {
        if(c[chi]==0)
        {
            pi[chi]=seed;
            dist[chi]=dist[seed]+1;
            dfs(G, c, dist, pi, chi);
        }
    }
}
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, va, vb, da, db;
        cin>>n>>va>>vb>>da>>db;
        va--;
        vb--;
        ve <ve <ll>> G(n);
        fr(i, 0, n-2)
        {
            ll a, b;
            cin>>a>>b;
            a--;
            b--;
            G[a].pb(b);
            G[b].pb(a);
        }
       // cout<<"x"<<endl;
        ve <ll> c(n, 0), dist(n, 0), pi(n, -1);
        dfs(G, c, dist, pi, 0);
       // cout<<"x"<<endl;
        ll seed=0;
        fr(i, 0, n-1)
        {
            if(dist[seed]<dist[i])
                seed=i;
        }
        setvector(i, c, 0, n);
        setvector(i, dist, 0, n);
        setvector(i, pi, -1, n);
        dfs(G, c, dist, pi, seed);
        ll dia=0;
        //cout<<"x"<<endl;
        fr(i, 0, n-1)
        {
            if(dia<dist[i])
            {
                dia=dist[i];
            }
        }
        ve <ll> arr1, arr2;
        ll pa=va;
        while(pa!=-1)
        {
           // cout<<pa<<endl;
            arr1.pb(pa);
            pa=pi[pa];
        }
        pa=vb;
        while(pa!=-1)
        {
            arr2.pb(pa);
            pa=pi[pa];
        }
        ll i=sz(arr1)-1;
        ll j=sz(arr2)-1;
        ll ance=seed;
        while((arr1[i]==arr2[j])&&(i>=0)&&(j>=0))
        {
            ance=arr1[i];
            i--;
            j--;
        }
        ll x=dist[va]+dist[vb]-2*dist[ance];
        if(x<=da)
        {
            cout<<"Alice"<<endl;
            continue;
        }
        if(dia<=2*da)
        {
            cout<<"Alice"<<endl;
            continue;
        }
        if(db>2*da)
        {
            cout<<"Bob"<<endl;
            continue;
        }
        else
        {
            cout<<"Alice"<<endl;
            continue;
        }
    }
}