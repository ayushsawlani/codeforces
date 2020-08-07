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
bool dfs1(vector <vector <ll>> &G,vector <ll> &c1,vector <ll> &c2,vector <ll> &v1,vector <ll> &v2,vector <ll> &cutil,vector <ll> &pi, ll seed);
bool dfs2(vector <vector <ll>> &G,vector <ll> &c1,vector <ll> &c2,vector <ll> &v1,vector <ll> &v2,vector <ll> &cutil,vector <ll> &pi, ll seed);
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve <ll> in(n);
    fr(i,0,n-1)
    {
        cin>>in[i+1];
    }
    ve <ve <ll>>dp(n,ve <ll>(2));
    fr(i,1,n)
    {
        dp[i][0]=i-in[i];
        dp[i][1]=i+in[i];
    }
    ve <ll> c1(n,0),c2(n,0),cutil(n,0),v1(n,0),v2(n,0),pi(n,-1);
    fr(i,1,n)
    {
        if(v1[i]==0)
            dfs1(dp,c1,c2,v1,v2,cutil,pi,i);
        if(v2[i]==0)
            dfs2(dp,c1,c2,v1,v2,cutil,pi,i);
    }
    fr(i,1,n)
    {
        if(c1[i]!=-1)
            cout<<c1[i]+i<<endl;
        else
        {
            cout<<c1[i]<<endl;
        }
        
    }
    
}

bool dfs1(vector <vector <ll>> &G,vector <ll> &c1,vector <ll> &c2,vector <ll> &v1,vector <ll> &v2,vector <ll> &cutil,vector <ll> &pi, ll seed)
{
    v1[seed]=1;
    ll n=G.size();
    cutil[seed]=1;
    if((G[seed][0]<0)||(G[seed][0]>=n))
    {
        c1[seed]=abs(seed-G[seed][0]);
        cutil[seed]=0;
        return true;
    }
    else if(G[seed][0]==0)
    {
        cutil[seed]=0;
        c1[seed]=-1;
        return false;
    }
    if(v2[G[seed][0]]==0)
    {
        if(dfs2(G,c1,c2,v1,v2,cutil,pi,G[seed][0]))
        {
            c1[seed]=c2[G[seed][0]]+abs(seed-G[seed][0]);
            cutil[seed]=0;
            return true;
        }
        else
        {
            cutil[seed]=0;
            c1[seed]=-1;
            return false;
        }
    }
    else
    {
        if(cutil[G[seed][0]])
        {
            c1[seed]=-1;
            cutil[seed]=0;
            return false;
        }
        else
        {
            if(c2[G[seed][0]]!=-1)
            {
                c1[seed]=c2[G[seed][0]]+abs(seed-G[seed][0]);
                cutil[seed]=0;
                return true;
            }
            else
            {
                c1[seed]=-1;
                cutil[seed]=0;
                return false;
            }
        }
        
    }
}
bool dfs2(vector <vector <ll>> &G,vector <ll> &c1,vector <ll> &c2,vector <ll> &v1,vector <ll> &v2,vector <ll> &cutil,vector <ll> &pi, ll seed)
{
    v2[seed]=1;
    ll n=G.size();
    if((G[seed][1]<0)||(G[seed][1]>=n))
    {
        c2[seed]=abs(seed-G[seed][1]);
        cutil[seed]=0;
        return true;
    }
    else if(G[seed][1]==0)
    {
        cutil[seed]=0;
        c2[seed]=-1;
        return false;
    }
    cutil[seed]=1;
    if(v1[G[seed][1]]==0)
    {
        if(dfs1(G,c1,c2,v1,v2,cutil,pi,G[seed][1]))
        {
            c2[seed]=c1[G[seed][1]]+abs(seed-G[seed][1]);
            cutil[seed]=0;
            return true;
        }
        else
        {
            cutil[seed]=0;
            c2[seed]=-1;
            return false;
        }
    }
    else
    {
        if(cutil[G[seed][1]])
        {
            c2[seed]=-1;
            cutil[seed]=0;
            return false;
        }
        else
        {
            if(c1[G[seed][1]]!=-1)
            {
                c2[seed]=c1[G[seed][1]]+abs(seed-G[seed][1]);
                cutil[seed]=0;
                return true;
            }
            else
            {
                c2[seed]=-1;
                cutil[seed]=0;
                return false;
            }
            
        }
    }
}
