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
void bfs(vector <vector<ll>> &g,vector <ll> &pi,vector <ll> &c, ve <ll> &dist, ll s )
{
    ll len_g=g.size();
    queue <ll> q;
    q.push(s);
    c[s]=1;     //it is better to declare c outside to improve efficiency if traversal is to be done a lot of times
    pi[s]=s;
    dist[s]=0;
    while(!(q.empty()))
    {
        ll temp=(q.front());
        q.pop();
        c[temp]=2;
        ll len_temp_adj=g[temp].size();
        for(auto i: g[temp])
        {
            if(c[i]==0)
            {
                dist[i]=dist[temp]+1;
                q.push(i);
                c[i]=1;
                pi[i]=temp;
            }
        }
    }
}
int main()
{
    //fastio
    ll n, m, k;
    cin>>n>>m>>k;
    ve <ll> spe(k);
    inarr(i, spe, k);
    fr(i, 0, k-1)
    {
        spe[i]--;
    }
    ve <ve <ll>> G(n);
    fr(i, 0, m-1)
    {
        ll a, b;
        cin>>a>>b;
        a--;
        b--;
        G[b].pb(a);
        G[a].pb(b);
    }
    ve <ll> c(n, 0), pi(n, -1), distfrom1(n, 0), distfromn(n, 0);
    bfs(G, pi, c, distfrom1, 0);
    setvector(i, c, 0, n);
    bfs(G, pi, c, distfromn, n-1);    
    ll yo=distfromn[0];
    ve <tuple <ll, ll, ll>> imp(k);
    fr(i, 0, k-1)
    {
        imp[i]={distfrom1[spe[i]]-distfromn[spe[i]], distfrom1[spe[i]], distfromn[spe[i]]};
    }
    sort(all(imp));
    ve <ll> suf(k);
    suf[k-1]=get<2>(imp[k-1]);
    frn(i, k-2, 0)
    {
        suf[i]=max(suf[i+1], get<2>(imp[i]));
    }
    ll ans=-inf;
    fr(i, 0, k-2)
    {
        ans=max(get<1>(imp[i])+suf[i+1]+1, ans);
    }
    if(ans>yo)
        ans=yo;
    cout<<ans<<endl;
}