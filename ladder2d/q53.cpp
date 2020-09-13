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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
ll d;
void djikstra(vector <vector <ll>> &G, ve <ll>&c,ve <ll> &pi,ve <ll> &priority, ve <ll> &cost, map <pair <ll,ll>,ll> &wt,ll seed)
{
    ll len_g=G.size();
    set <pair <ll,ll>> pq;
    pair <ll,ll> temp;
    temp.first=0;
    temp.second=seed;
    c[seed]=1;
    pi[seed]=-1;
    priority[seed]=0;
    pq.insert(temp);
    while(!(pq.empty()))
    {
        pair <ll,ll>visited=(*(pq.begin()));
        pq.erase(pq.begin());
        c[visited.second]=2;
        ll parent=pi[visited.second];
        for(auto i=G[visited.second].begin();i!=G[visited.second].end();i++)
        {
            pair <ll,ll> current;
            current.first=visited.second;
            current.second=(*i);
            ll newpri=wt[current]*d+visited.fi-cost[visited.se];
            if(c[(*i)]==1)
            {
                if(newpri<priority[*i])
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
                priority[(*i)]=newpri;
                pair <ll,ll> tobepushed;
                tobepushed.first=priority[*i];
                tobepushed.second=(*i);
                pq.insert(tobepushed);
                pi[*i]=visited.second;
                c[*i]=1;
            }
        }
    }
}
ll manhatt(pair <ll,ll> i,pair <ll,ll> j)
{
    return abs(i.fi-j.fi)+abs(i.se-j.se);
}
int main()
{
    //fastio
    ll n, d;
    cin>>n>>d;
    ve <ll> cost(n, 0);
    fr(i, 1, n-2)
    {
        cin>>cost[i];
    }
    ve <pair <ll,ll>> poi(n);
    fr(i, 0, n-1)
    {
        cin>>poi[i].fi>>poi[i].se;
    }
    ve <ve <ll>> G(n);
    map <pair <ll,ll>,ll> wt;
    fr(i, 0, n-1)
    {
        fr(j, 0, n-1)
        {
            if(i!=j)
            {
                G[i].pb(j);
                wt[pair <ll,ll>(i, j)]=manhatt(poi[i], poi[j])*d-cost[i];
            }
        }
    }
    ve <ll>priority(n, inf);
    priority[0]=0;
    fr(i, 0, n-1)
    {
        for(auto it: wt)
        {
            pair <ll,ll> edge=it.fi;
            ll wei=it.se;
            if(priority[edge.fi]!=inf)
            {
                priority[edge.se]=min(priority[edge.fi]+wei, priority[edge.se]);
            }
        }
    }
    cout<<max(priority[n-1], (ll)0)<<endl;
}