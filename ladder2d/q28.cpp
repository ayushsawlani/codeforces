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
const ll inf = 1e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
pair <ll,ll> dfs(vector <vector <ll>> &G,vector <ll> &c,vector <ll> &pi, ve<ll> &key,ll seed)
{
    pair <ll,ll> ans(0,0);    
    c[seed]=1;
    ll flag=1;
    for(auto i=G[seed].begin();i!=G[seed].end();i++)
    {
        if(pi[seed]!=(*i))
            pi[(*i)]=seed;
        if(!(c[(*i)]))
        {
            flag=0;
            pair <ll,ll> x=dfs(G,c,pi,key,(*i));
            ans.fi=max(ans.fi,x.fi);            
            ans.se=max(ans.se,x.se);
        }
    }
    key[seed]+=(ans.fi-ans.se);
    ans.fi+=max((ll)0,-key[seed]);
    ans.se+=max((ll)0,key[seed]);
    return ans;
}
int main()
{
    //fastio
    ll n,m;
    cin>>n;
    m=n-1;
    ve <ll> key(n),c(n,0),pi(n,-1);
    ve <ll> leaf;
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
    inarr(i,key,n);
    pair <ll,ll> ans=dfs(G, c, pi, key, (ll)0);
    cout<<ans.fi+ans.se<<endl;
//*/
}