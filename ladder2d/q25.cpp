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
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
int main()
{
    //fastio
    ll n,m;
    cin>>n>>m;
    ve <string> in(n);
    fr(i,0,n)
    {
        cin>>in[i];
    }
    ve <ve <ll>> dist(n,ve <ll>(m,inf));
    ll s_i,s_j,st_i,st_j;
    fr(i,0,n)
    {
        fr(j,0,m)
        {
            if(in[i][j]=='E')
            {
                s_i=i;
                s_j=j;
            }
            else if(in[i][j]=='S')
            {
                st_i=i;
                st_j=j;
            }
        }
    }
    ve <ve <ll>> color(n,ve <ll> (m,0));
    dist[s_i][s_j]=0;
    color[s_i][s_j]=0;
    queue <pair <ll,ll>> bfs;
    bfs.push(pair <ll,ll>(s_i,s_j));
    while(!(bfs.empty()))
    {
        pair <ll,ll> seed=bfs.front();
        bfs.pop();
        s_i=seed.fi;
        s_j=seed.se;
        color[s_i][s_j]=1;
        if(s_i>0)
        {
            if((in[s_i-1][s_j]!='T')&&(color[s_i-1][s_j]==0))
            {
                dist[s_i-1][s_j]=dist[s_i][s_j]+1;
                color[s_i-1][s_j]=1;
                bfs.push(pair <ll,ll>(s_i-1,s_j));
            }
        }
        if(s_j>0)
        {
            if((in[s_i][s_j-1]!='T')&&(color[s_i][s_j-1]==0))
            {
                dist[s_i][s_j-1]=dist[s_i][s_j]+1;
                color[s_i][s_j-1]=1;
                bfs.push(pair <ll,ll>(s_i,s_j-1));
            }
        }
        if(s_i<n-1)
        {
            if((in[s_i+1][s_j]!='T')&&(color[s_i+1][s_j]==0))
            {
                dist[s_i+1][s_j]=dist[s_i][s_j]+1;
                color[s_i+1][s_j]=1;
                bfs.push(pair <ll,ll>(s_i+1,s_j));
            }
        }
        if(s_j<m-1)
        {
            if((in[s_i][s_j+1]!='T')&&(color[s_i][s_j+1]==0))
            {
                dist[s_i][s_j+1]=dist[s_i][s_j]+1;
                color[s_i][s_j+1]=1;
                bfs.push(pair <ll,ll>(s_i,s_j+1));
            }
        }
    }
    ll com=dist[st_i][st_j];
    ll ans=0;
    fr(i,0,n)
    {
        fr(j,0,m)
        {
            if((in[i][j]!='S')&&(in[i][j]!='E'))
            {
                if((dist[i][j]<=dist[st_i][st_j]))
                {
                    ans+=in[i][j]-'0';
                }
            }
        }
    }
    cout<<ans<<endl;
}