#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
#define fr(i, a, b); for (int i = a; i < b; i++)
#define frn(i, a, b); for (int i = a; i > b; i--)
#define mk make_pair
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;

int main()
{
    //fastio
        ll n,m;
    cin>>n>>m;
    ve <ll> color(n);
    inarr(i,color,n); 
    vector <vector <ll>> G;
    for(ll i=0;i<n;i++)
    {
        vector <ll> temp;
        G.push_back(temp);
    }
    map <ll,ve<ll>> colorset;
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    fr(i,0,n)
    {
        if(colorset.find(color[i])!=colorset.end())
        {
            colorset[color[i]].pb(i);
        }
        else
        {
            ve <ll> temp=(*(new ve <ll>));
            temp.pb(i);
            colorset[color[i]]=temp;
        }
    }
    ve <ll> count(100007,0);
    for(auto it=colorset.begin();it!=colorset.end();it++)
    {
        set <ll> temp;
        temp.insert((*it).first);
        fr(i,0,(*it).second.size())
        {
            for(int j=0;j<G[(*it).second[i]].size();j++)
                temp.insert(color[G[(*it).second[i]][j]]);
        }   
        count[(*it).first]=temp.size();
    }
    ll max_i=0;
    fr(i,0,100007)
    {
        if(count[max_i]<count[i])
            max_i=i;
    }
    //cout<<count[4]<<" "<<count[2]<<endl;
    cout<<max_i<<endl;
}