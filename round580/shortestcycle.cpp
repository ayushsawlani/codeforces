#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll bfs(map <ll,vector<ll>> &g,map <ll,ll> dist,map <ll,ll> c,map <ll,ll>pi,ll s )
{
    ll len_g=g.size();
    queue <ll> q;
    q.push(s);
    c[s]=1;     //it is better to declare c outside to improve efficiency if traversal is to be done a lot of times
    pi[s]=s;
    dist[s]=0;
    ll ans=-1;
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
            else if((pi[temp]!=g[temp][i])&&(pi[g[temp][i]]!=temp))
            {
                if(ans==-1)
                    ans=dist[temp]+dist[g[temp][i]]+1;
                else
                {
                    ans=(min(ans,dist[temp]+dist[g[temp][i]]+1));
                }
                
            }
        }
    }
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    vector <ll> binary[65];
    vector <ll> relevant;
    ll s=a[0];
    for(ll i=0;i<n;i++)
    {
        ll temp=a[i];
        ll c=0;
        while(temp>0)
        {
            if((temp%2==1))
                binary[c].push_back(a[i]);
            c++;
            temp=temp/2;
        }
    }
    map <ll,vector <ll>> G;
    for(ll i=0;i<n;i++)
    {
        vector <ll> temp;
        G[a[i]]=temp;
    }
    for(ll i=0;i<65;i++)
    {
        if(binary[i].size()>2)
        {
            cout<<3<<endl;
            return 0;
        }
        else if(binary[i].size()==2)
        {
            relevant.push_back(binary[i][0]);
            relevant.push_back(binary[i][1]);
            G[binary[i][0]].push_back(binary[i][1]);
            G[binary[i][1]].push_back(binary[i][0]);
        }
    }
    ll ans=-1;
    for(ll i=0;i<relevant.size();i++)
    {
        map <ll,ll> c,pi,dist;
        for(ll i=0;i<relevant.size();i++)
        {
            c[relevant[i]]=0;
            pi[relevant[i]]=-1;
            dist[relevant[i]]=-1;
        }
        ll x=bfs(G,dist,c,pi,relevant[i]);
        if(x!=-1)
        {
            if(ans==-1)
                ans=x;
            else
            {
                ans=min(ans,x);
            }
        }
        
    }
    cout<<ans<<endl;
}