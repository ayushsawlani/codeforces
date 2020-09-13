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
void dfs_for_LCA(vector <vector <ll>> &G,vector <vector <ll>> &ancestor,vector <ll> &dist,vector <ll> &c,vector <ll> &pi, ll seed)
{
    ll log=sz(ancestor[seed]);
    c[seed]=1;
    ancestor[seed][0]=pi[seed];
    if(ancestor[seed][0]==-1)
        ancestor[seed][0]=seed;
    for(ll j=1;j<log;j++)
        ancestor[seed][j]=ancestor[ancestor[seed][j-1]][j-1];
    for(auto i=G[seed].begin();i!=G[seed].end();i++)
    {
        if(!(c[(*i)]))
        {
            dist[*i]=dist[seed]+1;
            pi[*i]=seed;
            ancestor[*i][0]=seed;
            dfs_for_LCA(G,ancestor,dist,c,pi,(*i));
        }
    }
}

ll LCA(ll a,ll b,vector <vector <ll>> &ancestor, vector <ll> &dist)
{
    if(a==b)
        return a;
    ll log=sz(ancestor[a]);
    ll _temp;
    if(dist[a]<dist[b])
        swap(a,b,_temp);
    frn(i,log-1,0)
    {
        if(dist[a]-pow(2,i)>=dist[b])
        {
            a=ancestor[a][i];
        }
    }
    if(a==b)
        return a;
    frn(i,log-1,0)
    {
        if(ancestor[a][i]!=ancestor[b][i])
        {
            a=ancestor[a][i];
            b=ancestor[b][i];
        }
    }
    return ancestor[a][0];
}
ll lcadistance(ll a,ll b,vector <vector <ll>> &ancestor,vector <ll>&dist)
{
    return dist[a]+dist[b]-2*dist[LCA(a,b,ancestor,dist)];
}
//pi initialized to The node where dfs starts
//c initialized to 0
//dist initialized inf dist[seed]=0;
// now go through the main

int main()
{
    //fastio
    ll n,m;
    cin>>n;
    m=n-1;
    vector <vector <ll>> G, ancestor;
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
    ll q;
    ll log=log2(n)+3;
    for(ll i=0;i<n;i++)
    {
        vector <ll> temp(log,0);
        ancestor.push_back(temp);
    }
    ve <ll> dist(n,0), c(n, 0), pi(n, 0);
    dfs_for_LCA(G, ancestor, dist, c, pi, 0 );
    cin>>q;
    while(q--)
    {
        ll x, y, a, b, k;
        cin>>x>>y>>a>>b>>k;
        x--;
        y--;
        a--;
        b--;
        ll utildist1=lcadistance(a, b, ancestor, dist);
        ll utildist2=lcadistance(a, x, ancestor, dist)+lcadistance(b, y, ancestor, dist)+1;
        ll utildist3=lcadistance(a, y, ancestor, dist)+lcadistance(b, x, ancestor, dist)+1;
        if(utildist1<=k)
        {
            if((utildist1+k)%2==0)
            {
                cout<<"YES"<<endl;
                continue;
            }
        }
        if(utildist2<=k)
        {
            if((utildist2+k)%2==0)
            {
                cout<<"YES"<<endl;
                continue;
            }
        }
        if(utildist3<=k)
        {
            if((utildist3+k)%2==0)
            {
                cout<<"YES"<<endl;
                continue;
            }
        }
        cout<<"NO"<<endl;
    }
}