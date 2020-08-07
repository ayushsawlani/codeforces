#include <bits/stdc++.h>
using namespace std;
#define M (ll)(1e9+7)
#define ll long long
void bfs(vector <vector<ll>> &g,vector <pair <ll,ll>> &interval,vector <ll> &children,vector <ll> &pi,vector <ll> &c,ll s )
{
    ll len_g=g.size();
    queue <ll> q;
    q.push(s);
    c[s]=1;     //it is better to declare c outside to improve efficiency if traversal is to be done a lot of times
    pi[s]=s;
    while(!(q.empty()))
    {
        ll temp=(q.front());
        q.pop();
        c[temp]=2;
        ll len_temp_adj=g[temp].size();
        ll imp=0;
        for(ll i=0;i<len_temp_adj;i++)
        {
            if(c[g[temp][i]]==0)
            {
                interval[g[temp][i]]=pair <ll,ll>(interval[temp].first+imp,interval[temp].first+imp+children[g[temp][i]]-1);
                imp+=children[g[temp][i]];
                q.push(g[temp][i]);
                c[g[temp][i]]=1;
                pi[g[temp][i]]=temp;
            }
        }
    }
}
void dfs(vector <vector <ll>> &G,vector <ll> &children,vector <ll> &c,vector <ll> &pi, ll seed)
{
    c[seed]=1;
    for(auto i=G[seed].begin();i!=G[seed].end();i++)
    {
        if(pi[seed]!=(*i))
            pi[(*i)]=seed;
        if(!(c[(*i)]))
        {
            dfs(G,children,c,pi,(*i));
        }   
    }
    if(G[seed].size()!=1)
    {
        for(auto i=G[seed].begin();i!=G[seed].end();i++)
        {
            if(pi[seed]!=(*i))
                children[seed]+=children[(*i)];
        }   
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n,k;
    cin>>n>>k;
    vector <ll> children(n,1),pi(n,-1),c(n,0);
    vector <vector <ll>> G;
    for(ll i=0;i<n;i++)
    {
        vector <ll> temp;
        G.push_back(temp);
    }
    ll m=n-1;
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(G,children,c,pi,0);
    
    vector <pair <ll,ll>> interval(n);
    interval[0]=pair <ll,ll>(0,n-1);
    for(ll i=0;i<n;i++)
    {
        c[i]=0;
    }
    bfs(G,interval,children,pi,c,0);
    for(ll j=0;j<k;j++)
    {
        ll ans=1;
        ll size;
        cin>>size;
        pair <ll,ll> intersection=pair <ll,ll>(0,n-1);
        for(ll i=0;i<size;i++)
        {
            ll input;
            cin>>input;
            if(input!=1)
            {
                //cout<<pi[input-1]+1<<" "<<interval[pi[input-1]].first<<" "<<interval[pi[input-1]].second<<endl;
                intersection.first=max(intersection.first,interval[pi[input-1]].first);
                intersection.second=min(intersection.second,interval[pi[input-1]].second);
            }
            if(intersection.first>intersection.second)
            {
                ans=0;
            }
        }
        if(ans)
            cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
    /**/
}