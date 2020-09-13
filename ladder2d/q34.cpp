#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
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
#define ll long long int
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e14;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
vector <vector <ll>> generatemst(vector <vector <ll>> &G, ve <ll> &c,ve <ll> &pi,ve <ll> &priority,map <pair <ll,ll>,ll> &wt,ve <set<pair <ll,ll> > >  &time)
{
    vector <vector <ll>> mst;
    ll len_g=G.size();
    for(ll i=0;i<len_g;i++)
    {
        vector <ll> temp;
        mst.push_back(temp);
    }
    set <pair <ll,ll>> pq;
    pair <ll,ll> temp;
    temp.first=0;
    temp.second=0;
    c[0]=1;
    pi[0]=-1;
    priority[0]=0;
    if(sz(time[0])!=0)
    {
        auto it=time[0].lower_bound(pair<ll,ll>(0,inf));
        if(it!=time[0].begin())
        {
            it--;
            if((it!=time[0].end())&&((0)!=len_g-1))
            {
                if(it->fi<=0)
                    priority[0]=max((ll)0,it->se+1);
            }
        }
    }
 
    pq.insert(temp);
    while(!(pq.empty()))
    {
        pair <ll,ll>visited=(*(pq.begin()));
        pq.erase(pq.begin());
        c[visited.second]=2;
        ll parent=pi[visited.second];
        if(parent!=-1)
        {
            mst[parent].push_back(visited.second);
            mst[visited.second].push_back(parent);
        }   
        for(auto i=G[visited.second].begin();i!=G[visited.second].end();i++)
        {
            pair <ll,ll> current;
            current.first=visited.second;
            current.second=(*i);
            ll newpriority=wt[current]+priority[visited.se];
            if(sz(time[*i])!=0)
            {
                auto it=time[*i].lower_bound(pair<ll,ll>(newpriority,inf));
                if(it!=time[*i].begin())
                {
                    it--;
                    if((it!=time[*i].end())&&((*i)!=len_g-1))
                    {
                        if(it->fi<=newpriority)
                            newpriority=max(newpriority,it->se+1);
                    }
                }
            }
            if(c[(*i)]==1)
            {
                if(newpriority<priority[*i])
                {
                    pair <ll,ll> tobeerased;
                    tobeerased.first=priority[*i];
                    tobeerased.second=(*i);
                    auto er=pq.find(tobeerased);
                    pq.erase(er);
                    c[*i]=0;
                }
            }
            if(c[(*i)]==0)
            {
                priority[(*i)]=newpriority;
                pair <ll,ll> tobepushed;
                tobepushed.first=priority[*i];
                tobepushed.second=(*i);
                pq.insert(tobepushed);
                pi[*i]=visited.second;
                c[*i]=1;
            }
        }
    }
    return mst;
}
set <pair <ll,ll>> compress_array(vector <ll> a, ll n)
{
    set <pair <ll,ll>> ans;
    if(n==0)
        return ans;
    ll i=0;
    ll c=1;
    while(i<n-1)
    {
        if(a[i]!=a[i+1]-1)
        {
            pair <ll,ll> temp;
            temp.first=a[i]-c+1;
            temp.second=a[i];
            ans.insert(temp);
            c=1;
        }
        else
        {
            c++;
        }
        i++;   
    }
    pair <ll,ll> temp;
    temp.first=a[i]-c+1;
    temp.second=a[i];
    ans.insert(temp);
    c=1;
    return ans;
}
int main()
{
    //fastio
        ll n,m;
    cin>>n>>m;
    vector <vector <ll>> G;
    for(ll i=0;i<n;i++)
    {
        vector <ll> temp;
        G.push_back(temp);
    }
    map <pair <ll,ll>,ll> wt;
    for(ll i=0;i<m;i++)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        a--;
        b--;
        wt[pair <ll,ll>(a,b)]=w;
        wt[pair <ll,ll>(b,a)]=w;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ve <set <pair <ll,ll>>> time(n);
    fr(i, 0, n )
    {
        ll x;
        cin>>x;
        ve <ll> temp(x);
        inarr(j,temp,x);
        time[i] = compress_array(temp,x);
    }
    ve <ll> c(n,0),pi(n,-1),priority(n,inf);
    generatemst(G,c,pi,priority,wt,time);
    cout<<(priority[n-1]<inf?priority[n-1]:-1)<<endl;
}