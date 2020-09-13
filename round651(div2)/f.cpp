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
ll distance(ll a,ll b,vector <vector <ll>> &ancestor,vector <ll>&dist)
{
    return dist[a]+dist[b]-2*dist[LCA(a,b,ancestor,dist)];
}
//pi initialized to The node where dfs starts
//c initialized to 0
//dist initialized inf dist[seed]=0;
// now go through the main
void dfs(ve <ve <ll>> &G, ve <ll> &c, ve <ll> &pi,  ve <ll> &dist, ll seed)
{
    c[seed]=1;
    for(auto j:G[seed])
    {
        if(c[j]==0)
        {
            pi[j]=seed;
            dist[j]=dist[seed]+1;
            dfs(G, c, pi, dist, j);
        }
    }
}
void ask(ve <ll> q)
{
    cout<<"?"<<" "<<sz(q)<<" ";
    outarr(i, q, sz(q));
    cout<<endl;
    cout.flush();
}
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll seed=0;
        ll log=log2(n)+3;
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
        ve <ll> c(n, 0), pi(n, -1), dist(n, 0);
        ve <ll> q;
        fr(i, 0, n-1)
        {
            q.pb(i+1);
        }
        ask(q);
        q.clear();
        ll node, l;
        cin>>node>>l;
        node--;
        dfs(G, c, pi, dist, node);
        ll i=1;
        ll j=l;
        while(i<j)
        {
            ll mid=(i+j+1)/2;
            fr(it, 0, n-1)
            {
                if(dist[it]==mid)
                    q.pb(it+1);
            }
            if(sz(q)==0)
            {
                j=mid-1;
                continue;
            }
            ask(q);
            q.clear();
            ll tnode, tl;
            cin>>tnode>>tl;
            if(tl==l)
            {
                i=mid;
            }
            else
            {
                j=mid-1;
            }
        }
        fr(it, 0, n-1)
        {
            if(dist[it]==i)
            {
                q.pb(it+1);
            }
        }
        ask(q);
        q.clear();
        ll ans1, tl;
        cin>>ans1>>tl;
        ll x=ans1-1;
        ve <ll> mark(n, 1);
        while(x!=node)
        {
            mark[x]=0;
            x=pi[x];   
        }
        ll ans2;
        fr(it, 0, n-1)
        {
            if((dist[it]==l-i)&&(mark[it]))
            {
                q.pb(it+1);
            }
        }
        ask(q);
        cin>>ans2>>tl;
        cout<<"!"<<" "<<ans1<<" "<<ans2<<endl;
        cout.flush();
        string s;
        cin>>s;
    }
}