#include <bits/stdc++.h>
using namespace std;
#define ll long long
void bfs(vector <set<ll>> &g,ll *pi,ll *dist,ll s)
{
    ll len_g=g.size();
    queue <ll> q;
    ll c[len_g];
    for(ll i=0;i<len_g;i++)
        c[i]=0;
    q.push(s);
    c[s]=1;     //it is better to declare c outside to improve efficiency if traversal is to be done a lot of times
    pi[s]=s;
    dist[s]=0;
    while(!(q.empty()))
    {
        ll temp=(q.front());
        q.pop();
        c[temp]=2;
        ll len_temp_adj=g[temp].size();
        for(auto i=g[temp].begin();i!=g[temp].end();i++)
        {
            if(c[*i]==0)
            {
                q.push(*i);
                c[*i]=1;
                pi[*i]=temp;
                dist[*i]=dist[temp]+1;
            }
        }
    }
}
vector <pair <ll,ll>> compress_array(vector <pair <ll,ll>> a, ll n)
{
    vector <pair <ll,ll>> ans;
    ll i=0;
    ll c=1;
    while(i<n-1)
    {
        if(a[i]!=a[i+1])
        {
            pair <ll,ll> temp;
            temp=a[i];
            ans.push_back(temp);
            c=1;
        }
        else
        {
            c++;
        }
        i++;   
    }
    pair <ll,ll> temp;
    temp=a[i];
    ans.push_back(temp);
    c=1;
    return ans;
}
int main()
{
    pair <ll,ll> source;
    pair <ll,ll> dest;
    cin>>source.first>>source.second>>dest.first>>dest.second;
    ll n;
    cin>>n;
    set <pair <ll,ll>> valid;
    for(ll i=0;i<n;i++)
    {
        ll r,a,b;
        cin>>r>>a>>b;
        for(ll j=a;j<=b;j++)
        {
            valid.insert(pair <ll,ll>(r,j));
        }
    }
    map <pair <ll,ll>,ll> c,dist;
    for(auto i=valid.begin();i!=valid.end();i++)
    {
        c[*i]=0;
        dist[*i]=-1;
        if(*i==source)
        {
            c[*i]=1;
            dist[*i]=0;
        }
    }
    queue <pair <ll,ll>> q;
    q.push(source);
    while(!(q.empty()))
    {
        pair <ll,ll> pre=q.front();
        q.pop();
        for(ll i=-1;i<=1;i++)
        {
            for(ll j=-1;j<=1;j++)
            {
                pair <ll,ll> tovisit(pre.first+i,pre.second+j);
                if((valid.find(tovisit)!=valid.end())&&(c[tovisit]==0))
                {
                    c[tovisit]=1;
                    dist[tovisit]=dist[pre]+1;
                    q.push(tovisit);
                }
            }
        }
    }
    cout<<dist[dest]<<endl;
}
