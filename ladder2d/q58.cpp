#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
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
//const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
void dfs(ve <string> &maze, ve<ve <ll>> &vis, pair <ll,ll> seed, ve <pair <ll,ll>> &temp)
{
    vis[seed.fi][seed.se]=1;
    ll n=sz(maze);
    ll m=sz(maze[0]);
    ll i=seed.fi;
    ll j=seed.se;
    temp.pb(seed);
    if(i>0)
    {
        if((vis[i-1][j]==0)&&(maze[i-1][j]!='#'))
        {
            dfs(maze, vis, mk(i-1, j), temp);
        }  
    }
    if(j>0)
    {
        if((vis[i][j-1]==0)&&(maze[i][j-1]!='#'))
        {
            dfs(maze, vis, mk(i, j-1), temp);
        }  
    }
    if(j<m-1)
    {
        if((vis[i][j+1]==0)&&(maze[i][j+1]!='#'))
        {
            dfs(maze, vis, mk(i, j+1), temp);
        }
    }
    if(i<n-1)
    {
        if((vis[i+1][j]==0)&&(maze[i+1][j]!='#'))
        {
            dfs(maze, vis, mk(i+1, j), temp);
        }
    }
}
bool  det(ve <ve <set <ll>>> &G, ve <ll> &c, ve <ll> &pi, ll seed,ve <pair <ll,ll>> &ref)
{
    c[seed]=1;
    bool ans=true;
    fr(i, 0, 3)
    {
        pair <ll,ll> _ref=ref[seed];
        if(i==0)
        {
            _ref.se++;
        }
        else if(i==1)
        {
            _ref.se--;
        }
        else if(i==2)
        {
            _ref.fi++;
        }
        else
        {
            _ref.fi--;
        }
        for(auto ele: G[seed][i])
        {
            if(c[ele]==0)
            {
                pi[ele]=seed;
                ref[ele]=_ref;
                bool res=det(G, c, pi, ele, ref);
                if(res)
                    return true;
            }
            else
            {
                if(ele!=pi[seed])
                {
                    if(ref[ele]!=_ref)
                    {
                        return true;
                    }
                }
            }
            
        }
    }
    return false;
}
void  dfsx(ve <ve <set <ll>>> &G, ve <ll> &c, ll seed)
{
    c[seed]=1;
    fr(i, 0, 3)
    {
        for(auto ele: G[seed][i])
        {
            if(c[ele]==0)
            {
                dfsx(G, c, ele);
            }
        }
    }
}
int main()
{
    fastio
    ll n, m;
    cin>>n>>m;
    ve <string> maze(n);
    inarr(i, maze, n);
    ve <ve <ll>> vis(n,ve <ll> (m, 0));
    pair <ll,ll> start;
    fr(i, 0, n-1)
    {
        fr(j, 0, m-1)
        {
            if(maze[i][j]=='S')
            {
                start=mk(i, j);
                break;
            }
        }
    }
    ve <ve <ll>>koli(n, ve<ll>(m, -1));
    ve <ve <pair <ll,ll>>> comp;
    fr(i, 0, n-1)
    {
        fr(j, 0, m-1)
        {
            if(maze[i][j]!='#')
            {
                if(vis[i][j]==0)
                {
                    comp.pb(ve <pair <ll,ll>>());
                    dfs(maze, vis, mk(i, j), comp[sz(comp)-1]);
                    for(auto it: comp[sz(comp)-1])
                    {
                        koli[it.fi][it.se]=sz(comp)-1;
                    }
                }
            }
        }
    }
    ve <ve <set <ll>>> G(sz(comp), ve <set <ll>>(4));
    fr(i, 0, n-1)
    {
        if(koli[i][0]!=-1)
        {
            if(koli[i][m-1]!=-1)
            {
                G[koli[i][0]][1].insert(koli[i][m-1]);
                G[koli[i][m-1]][0].insert(koli[i][0]);
            }
        }
    }
    fr(i, 0, m-1)
    {
        if(koli[0][i]!=-1)
        {
            if(koli[n-1][i]!=-1)
            {
                G[koli[0][i]][3].insert(koli[n-1][i]);
                G[koli[n-1][i]][2].insert(koli[0][i]);
            }
        }
    }
    ll s1=koli[start.fi][start.se];
    ve <ll> c(sz(G), 0), pi(sz(G), -1); 
    dfsx(G, c, s1);
    fr(i, 0, m-1)
    {
        if(koli[0][i]!=-1)
        {
            if(koli[n-1][i]!=-1)
            {
                if((G[koli[0][i]][0].find(koli[n-1][i])!=G[koli[0][i]][0].end())&&(c[koli[0][i]]))
                {
                    cout<<"Yes"<<endl;
                    return 0;
                }
                if((G[koli[0][i]][1].find(koli[n-1][i])!=G[koli[0][i]][1].end())&&(c[koli[0][i]]))
                {
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    setvector(i, c, 0, sz(c));
    ve <pair <ll,ll>> dist(sz(G), mk(0, 0));
    string ans="No";
    if(det(G, c, pi, koli[start.fi][start.se], dist))
    {
        ans="Yes";
    }    
    cout<<ans<<endl;
}