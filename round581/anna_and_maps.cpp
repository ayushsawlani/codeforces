#include <bits/stdc++.h>
using namespace std;
#define ll long long
void bfs(vector <vector<ll>> &g,ll *dist,ll *c,ll *pi,ll s )
{
    ll len_g=g.size();
    queue <ll> q;
    q.push(s);
    dist[s]=0;
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
                q.push(g[temp][i]);
                c[g[temp][i]]=1;
                pi[g[temp][i]]=temp;
                dist[g[temp][i]]=dist[temp]+1;
            }
        }
    }
}
int main()
{
    ll n;
    cin>>n;
    vector <vector <ll>> G;
    for(ll i=0;i<n;i++)
    {
        vector <ll> temp;
        G.push_back(temp);
    }
    for(ll i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(ll j=0;j<n;j++)
        {
            if(s[j]=='1')
                G[i].push_back(j);
        }
    }
    ll c[n],pi[n];
    vector <ll> ans;
    
    ll m;
    cin>>m;
    ll p[m];
    for(ll i=0;i<m;i++)
    {
       cin>>p[i];
        p[i]=p[i]-1;
    }
    ll **dist=(ll**)(malloc(n*sizeof(ll*)));
    for(ll i=0;i<n;i++)
        dist[i]=(ll *)(malloc(n*sizeof(ll)));
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            c[j]=0;
            pi[j]=-1;

        }
        bfs(G,dist[i],c,pi,i);
    }
    ll x=0;
    for(ll i=0;i<m;i++)
    {
        i=x;
        ans.push_back(p[i]);
        if(i>=m)
            break;
        x=i+1;
        for(ll j=i+1;((j<m)&&(j<n+i+1));j++)
        {
            if(dist[p[i]][p[j]]==j-i)
            {
                x=j;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(ll i=0;i<ans.size();i++)
    {
        cout<<ans[i]+1<<" ";
    }
    cout<<endl;
}