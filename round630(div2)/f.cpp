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
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
void dfs(vector <vector <ll>> &G,vector <ll> &children,vector <ll> &c,vector <ll> &pi, ll seed)
{
    c[seed]=1;
    for(auto i=G[seed].begin();i!=G[seed].end();i++)
    {
        if(pi[seed]!=(*i))
            pi[(*i)]=seed;
        if(!(c[(*i)]))
        {
            dfs(G,children,c,pi,(*i));
        }   
    }
        for(auto i=G[seed].begin();i!=G[seed].end();i++)
        {
            if(pi[seed]!=(*i))
                children[seed]+=children[(*i)];
            fr(j,0,sz(G[*i]))
            {
                if((pi[*i]!=G[(*i)][j])&&((*i)!=pi[seed]))
                {
                    cout<<(*i)<<" "<<G[*i][j]<<endl;
                    children[seed]+=children[G[*i][j]];
                }
            }
        }   
}
int main()
{
    //fastio
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
    ve <ll> c(n,0),pi(n,-1),children(n,1);
    dfs(G,children,c,pi,0);
    cout<<children[0]<<endl;
}