#include <bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(vector <vector <ll>> &G,ll *change,vector <ll> &ans_vec,ll *c,ll *pi,ll *init,ll*goal, ll seed)
{
    if(pi[seed]==-1)
    {
        if(init[seed]!=goal[seed])
        {
            ans_vec.push_back(seed);
            change[seed]=1;
        }
    }
    else if(pi[pi[seed]]==-1)
    {
        if(init[seed]!=goal[seed])
        {
            ans_vec.push_back(seed);
            change[seed]=1;
        }
    }
    else
    {
        ll gf=pi[pi[seed]];
        if((init[seed]==goal[seed])&&(change[gf]==1))
        {
            ans_vec.push_back(seed);
            change[seed]=0;            
        }
        else if((init[seed]!=goal[seed])&&(change[gf]==0))
        {
            ans_vec.push_back(seed);
            change[seed]=1;
        }
        else
        {
            change[seed]=change[gf];
        }
    }
    c[seed]=1;
    for(auto i=G[seed].begin();i!=G[seed].end();i++)
    {
        if(pi[seed]!=(*i))
            pi[(*i)]=seed;
        if(!(c[(*i)]))
        {
            dfs(G,change,ans_vec,c,pi,init,goal,(*i));
        }   
    }
}
int main()
{
    ll n,m;
    cin>>n;
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
    ll change[n],c[n],pi[n],init[n],goal[n];
    memset(change,0,n*sizeof(ll));
    memset(c,0,n*sizeof(ll));
    memset(pi,-1,n*sizeof(ll));
    for(ll i=0;i<n;i++)
    {
        cin>>init[i];
    }
    for(ll i=0;i<n;i++)
    {
        cin>>goal[i];
    }
    vector <ll> ans_vec;
    dfs(G,change,ans_vec,c,pi,init,goal,0);
    cout<<ans_vec.size()<<endl;
    for(auto i=ans_vec.begin();i!=ans_vec.end();i++)
    {
        cout<<(*i)+1<<endl;
    }
}