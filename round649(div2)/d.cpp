#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ceil (ll)ceil
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
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
ll var=inf;
pair <ll,ll> check(-1, -1);
void ver(ve <ve <ll>> &G, ve <ll> &c, ve <ll> &pi,ve <ll> &dist, ll seed)
{
    c[seed]=1;
    pair <ll,ll> ans(-1, -1);
    for(auto j:G[seed])
    {
        if(c[j]==0)
        {
            pi[j]=seed;
            dist[j]=dist[seed]+1;
            ver(G, c, pi, dist, j);
        }
        else if(pi[seed]!=j)
        {
            if((dist[seed]-dist[j]<var)&&(dist[seed]-dist[j]>0))
            {
                var=dist[seed]-dist[j];
                check=mk(j, seed);
            }
        }
    }
}
void prinfo(ve <ll> &pi, ll x, ll stop)
{
    if(x!=stop)
    {
        cout<<x+1<<" ";
        prinfo(pi, pi[x], stop);
    }
}
void prinbac(ve <ll> pi,ll x,ll stop)
{
    if(x!=stop)
    {
        prinbac(pi, pi[x], stop);
        cout<<x+1<<" ";
    }
}
void dfs2(ve <ve <ll>> &G, ve <ll> &c, ve <ll> &pi, ll seed, ve <bool> &flag, ve <ll> &val)
{
    c[seed]=1;
    for(auto j:G[seed])
    {
        if(c[j]==0)
        {
            pi[j]=seed;
            dfs2(G, c, pi, j, flag, val);
        }
    }
    ll m1=0;
    ll m2=0;
    for(auto chi:G[seed])
    {
        if(chi!=pi[seed])
        {
            m1+=val[chi];
            for(auto grandchi:G[chi])
            {
                if(pi[chi]!=grandchi)
                {
                    m2+=val[grandchi];
                }
            }
        }
    }
    if(m1>m2+1)
    {
        flag[seed]=false;
    }
    val[seed]=max(m1, m2+1);
}
void dfs3(ve <ve <ll>> &G, ve <ll> &c, ve <ll> &pi, ll seed, ve <bool> &flag, ve <ll> &ans)
{
    c[seed]=1;
    if(flag[seed])
    {
        ans.pb(seed);
        for(auto j:G[seed])
        {
            if(j!=pi[seed])
            {
                for(auto jj:G[j])
                {
                    if(pi[j]!=jj)
                    {
                        dfs3(G, c, pi, jj, flag, ans);
                    }
                }
            }
        }
    }
    else
    {
        for(auto j:G[seed])
        {
            if(j!=pi[seed])
            {
                dfs3(G, c, pi, j, flag, ans);
            }
        }
    }
    
}
int main()
{
    //fastio
    ll n, m, k;
    cin>>n>>m>>k;
    ve <ve <ll>> G(n, ve<ll>());
    fr(i, 0, m-1)
    {
        ll a, b;
        cin>>a>>b;
        a--;
        b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    ve <ll> c(n, 0), pi(n, -1), dist(n, inf), val(n, 0);
    ve <bool> flag(n, true);
    dist[0]=0;
    ver(G, c, pi, dist, 0);
    if(check!=pair <ll,ll>(-1, -1))
    {
    //    cout<<"x"<<endl;
        ll start=check.fi;
        ll end=check.se;
        ve <ll> ans;
        ll ele=end;
        while(ele!=start)
        {
            ans.pb(ele);
            ele=pi[ele];
        }
        ans.pb(start);
        if(sz(ans)>k)
        {
            cout<<1<<endl;
            ll cou=0;
            fr(i, 0, sz(ans)-1)
            {
                if(cou==ceil(k/2.000))
                {
                    break;
                }
                if(i%2==0)
                {
                    cou++;
                    cout<<ans[i]+1<<" ";
                }
            }
            cout<<endl;
        }
        else
        {
            cout<<2<<endl;
            cout<<sz(ans)<<endl;
            fr(i, 0, sz(ans)-1)
            {
                cout<<ans[i]+1<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
     //   cout<<"y"<<endl;
        setvector(i, c, 0, n);
        setvector(i, pi, -1, n);
        cout<<1<<endl;
        ve <ll> ans;
        dfs2(G, c, pi, 0, flag, val);
        setvector(i, c, 0, n);
        dfs3(G, c, pi, 0, flag, ans);
        ll x=ceil(k/2.000);
        fr(i, 0, x-1)
        {
            cout<<ans[i]+1<<" ";
        }
        cout<<endl;
    }
}