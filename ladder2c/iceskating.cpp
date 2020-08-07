#include <bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(vector <vector <ll>> &G,ll *c,ll *pi, ll seed)
{
    c[seed]=1;
    for(auto i=G[seed].begin();i!=G[seed].end();i++)
    {
        if(pi[seed]!=(*i))
            pi[(*i)]=seed;
        if(!(c[(*i)]))
        {
            dfs(G,c,pi,(*i));
        }   
    }
}
ll number_of_disconnected_components(vector <vector <ll>> &G,ll *c,ll*pi)
{
    ll n=G.size();
    ll i=0;
    ll ans=0;
    while(i<n)
    {
        if(!(c[i]))
            ans++;
        dfs(G,c,pi,i);
        i++;
    }
    return ans-1;
}
int main()
{
    ll n;
    cin>>n;
    vector <pair <ll,ll>> v;
    for(ll i=0;i<n;i++)
    {
        pair <ll,ll> temp;
        cin>>temp.first>>temp.second;
        v.push_back(temp);
    }
    vector <vector <ll>> G;
    for(ll i=0;i<n;i++)
    {
        vector <ll> temp;
        G.push_back(temp);
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if((v[i].first==v[j].first)||(v[i].second==v[j].second))
            {
                G[i].push_back(j);
            }
        }
    }
    ll c[n]={0},pi[n]={0};
    cout<<number_of_disconnected_components(G,c,pi)<<endl;
}