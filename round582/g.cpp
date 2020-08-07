#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 200001
ll dsu_find(ll x,ll *c)
{
    return c[x];
}
ll nc2(ll x)
{
    return (((x)*(x-1))/2);
}
ll dsu_union(ll wt,ll a, ll b, ll *c, set <ll> *s,ll *setedge)
{
    ll max=b;
    ll min=a;
    if(s[a].size()>s[b].size())
    {
        max=a;
        min=b;
    }
    ll size_max=s[max].size();
    ll size_min=s[min].size();
    ll x=((size_max)*(size_max-1))/2+((size_min)*(size_min-1))/2;
    while(size_min>0)
    {
        auto i=s[min].begin();
        ll x=(*i);
        c[x]=max;
        s[max].insert(x);
        s[min].erase(i);
        size_min--;
        size_max++;
    }
    setedge[max]=wt;
    setedge[min]=0;
    return size_max;
}
int main()
{
    ll n,m,q;
    cin>>n>>q;
    m=n-1;
    vector <vector <ll>> G;
    map <pair <ll,ll>,ll> wtlist;
    vector <pair <ll,pair <ll,ll>>> v;
    for(ll i=0;i<n;i++)
    {
        vector <ll> temp;
        G.push_back(temp);
    }
    for(ll i=0;i<m;i++)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
        pair <ll,ll>p1(a,b);
        pair <ll,ll>p2(a,b);
        wtlist[p1]=w;
        wtlist[p2]=w;
        pair <ll, pair <ll,ll>> p3;
        p3.first=w;
        p3.second=p1;
        v.push_back(p3);
    }
    sort(v.begin(),v.end());
    ll c[n],setedge[n];
    set <ll> s[n];
    for(ll i=0;i<n;i++)
    {
        c[i]=i;
        s[i].insert(i);
        setedge[i]=0;
    }
    ll ans[M]={0};
    ll i=0;
    while(i<m)
    {
        ll size1=s[c[v[i].second.first]].size();
        ll size2=s[c[v[i].second.second]].size();
        ll size3=dsu_union(v[i].first,c[v[i].second.first],c[v[i].second.second],c,s,setedge);
        ans[v[i].first]+=(nc2(size3)-nc2(size1)-nc2(size2));
        i++;
    }
    i=1;
    ll x=ans[0];
    while(i<M)
    {
        ans[i]+=(ans[i-1]);
        i++;
    }
    ll t[q];
    for(i=0;i<q;i++)
    {
        cin>>t[i];   
    }
    for(i=0;i<q;i++)
    {
        cout<<ans[t[i]]<<" ";
    }
    cout<<endl;
}