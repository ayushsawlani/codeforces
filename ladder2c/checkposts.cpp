#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
void dfs(vector <vector <ll>> &G,ll *c,ll *pi, ll seed,vector <ll> &topsorted )
{
    c[seed]=1;
    for(auto i=G[seed].begin();i!=G[seed].end();i++)
    {
        if(pi[seed]!=(*i))
            pi[(*i)]=seed;
        if(!(c[(*i)]))
        {
            dfs(G,c,pi,(*i),topsorted);
        }   
    }
    topsorted.push_back(seed);
}
vector <vector <ll>> scc(vector <vector <ll>> G, vector <ll> &topsorted)
{
    ll n=G.size();
    vector <vector <ll>> reverseG2;
    for(ll i=0;i<n;i++)
    {
        vector <ll> temp;
        reverseG2.push_back(temp);
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<G[i].size();j++)
        {
            reverseG2[G[i][j]].push_back(i);
        }
    }

    ll *c=(ll *)(malloc(n*sizeof(ll)));
    ll *pi=(ll *)(malloc(n*sizeof(ll)));
    for(ll i=0;i<n;i++)
    {
        c[i]=0;
        pi[i]=-1;
    }
    vector <vector <ll>> ans;
    for(ll i=0;i<n;i++)
    {
        vector <ll> temp;
        ans.push_back(temp);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(c[topsorted[i]]==0)
        {
            dfs(reverseG2,c,pi,topsorted[i],ans[topsorted[i]]);
        }
    } 
    return ans;
}


int main()
{
    ll n;
    cin>>n;
    ll cost[n];
    for(ll i=0;i<n;i++)
    {
        cin>>cost[i];
    }
    ll m;
    cin>>m;
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
    }
    vector <ll> topsorted;

    ll c[n],pi[n];
    for(ll i=0;i<n;i++)
    {
        c[i]=0;
        pi[i]=-1;
    }
    for(ll i=0;i<n;i++)
    {
        if(c[i]==0)
            dfs(G,c,pi,i,topsorted);
    }
    vector <vector <ll>> s=scc(G,topsorted);  
    ll ans=0;
    ll ways=1;
    for(ll i=0;i<n;i++)
    {
        ll freq=0;
        ll m=1000000000;
        for(ll j=0;j<s[i].size();j++)
        {
            m=min(m,cost[s[i][j]]);
        }
        if(s[i].size())
        {
            ans+=m;
            for(ll j=0;j<s[i].size();j++)
            {
                if(cost[s[i][j]]==m)
                    freq++;
            }
            ways*=(freq%M);
            ways=(ways%M);
        }
    }
    cout<<ans<<" "<<ways<<endl;

}