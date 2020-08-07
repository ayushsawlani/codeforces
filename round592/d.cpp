#include <bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(vector <vector <ll>> &G,ll *color,ll *c,ll *pi, ll seed)
{
    c[seed]=1;
    for(auto i=G[seed].begin();i!=G[seed].end();i++)
    {
        if(pi[seed]!=(*i))
        {
            pi[(*i)]=seed;
        }
        if(!(c[(*i)]))
        {
            dfs(G,color,c,pi,(*i));
        }
    }
}
void bfs(vector <vector<ll>> &g,ll *color,ll *pi,ll s )
{
    ll len_g=g.size();
    queue <ll> q;
    ll c[len_g];
    for(ll i=0;i<len_g;i++)
        c[i]=0;
    q.push(s);
    c[s]=1;     //it is better to declare c outside to improve efficiency if traversal is to be done a lot of times
    pi[s]=s;
    while(!(q.empty()))
    {
        ll temp=(q.front());
        q.pop();
        c[temp]=2;
        ll len_temp_adj=g[temp].size();
        for(ll i=0;i<len_temp_adj;i++)
        {
            if(c[g[temp][i]]==0)
            {
                color[g[temp][i]]=(color[temp]+1)%3;
                q.push(g[temp][i]);
                c[g[temp][i]]=1;
                pi[g[temp][i]]=temp;
            }
        }
    }
}   
int main()
{
    ll n,m;
    cin>>n;
    m=n-1;
    ll colorx[3][n];
    for(ll i=0;i<n;i++)
    {
        cin>>colorx[0][i];
    }
    for(ll i=0;i<n;i++)
    {
        cin>>colorx[1][i];
    }
    for(ll i=0;i<n;i++)
    {
        cin>>colorx[2][i];
    }
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
    ll color[n],c[n],pi[n];
    for(ll i=0;i<n;i++)
    {
        pi[i]=-1;
        color[i]=0;
        c[i]=0;
    }
    ll s=0;
    for(ll i=0;i<n;i++)
    {
        if(G[i].size()>2)
        {
            cout<<-1<<endl;
            return 0;
        }
        else if(G[i].size()==1)
        {
            s=i;
        }
    }
    bfs(G,color,pi,s);
    ll ans=INT64_MAX;
    ll x=0,y=0;
    for(ll i=0;i<2;i++)
    {
        for(ll j=0;j<3;j++)
        {
            ll cost=0;
                for(ll k=0;k<n;k++)
                {
                    cost+=colorx[(j+((i+1)*color[k])%3)%3][k];
                }
            if(cost<ans)
            {
                ans=cost;
                x=i;
                y=j;
            }
        }
    }
    cout<<ans<<endl;
    for(ll i=0;i<n;i++)
    {
        cout<<((((x+1)*color[i])%3+y)%3)+1<<" ";
    }
    cout<<endl;
}