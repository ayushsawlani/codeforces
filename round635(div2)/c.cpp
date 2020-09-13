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
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
void dfs(vector <vector <ll>> &G,vector <ll> &dist,ve <ll> &children,vector <ll> &c,vector <ll> &pi, ll seed)
{
    c[seed]=1;
    for(auto i=G[seed].begin();i!=G[seed].end();i++)
    {
        if(pi[seed]!=(*i))
            pi[(*i)]=seed;
        if(!(c[(*i)]))
        {
            dist[*i]=dist[seed]+1;
            dfs(G,dist,children,c,pi,(*i));
        }   
    }
    fr(i, 0, sz(G[seed]))
    {
        if(G[seed][i]!=pi[seed])
        {
            children[seed]+=children[G[seed][i]];
        }
    }
}
int main()
{
    ll n,m,k;
    cin>>n>>k;
    m=n-1;
    vector <vector <ll>> G;
    for(ll i=0;i<n;i++)
    {
        vector <ll> temp;
        G.push_back(temp);
    }
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ve<ll>c(n,0),pi(n,-1),dist(n,0),children(n,1);
    dfs(G,dist,children,c,pi,0);
    ve <ll> util(n,0);
    fr(i, 0, n)
    {
        util[i]=dist[i]-(children[i]-1);
    }
    sort(util.begin(), util.end());
    ll ans=0;
    frn(i,n-1,n-1-k)
    {
        ans+=util[i];
    }
    cout<<ans;
}