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
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
ll d;
ll dfs(vector <vector <ll>> &G,vector <ll> &c,vector <ll> &pi, ll seed)
{
    c[seed]=1;
    ll ans=1;
    for(auto i=G[seed].begin();i!=G[seed].end();i++)
    {
        if(pi[seed]!=(*i))
            pi[(*i)]=seed;
        if(!(c[(*i)]))
        {
            ans*=(dfs(G,c,pi,(*i))+1);
            ans%=mod;
        }   
    }
    return ans;
//    cout<<subtreewith[seed]<<endl;
//    cout<<subtreewout[seed]<<endl;
}

int main()
{
    //fastio
        ll n,m;
    cin>>d>>n;
    m=n-1;
    vector <vector <ll>> G;
    ve <ll> value(n);
    inarr(i, value,n);
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
    ve <ll> c(n,0),pi(n,-1);
    ve <ll> check(2004, 0);
    ll ans=0;
    fr(i, 0, n)
    {
        setvector(c, 1, n);
        fr(j, 0, n)
        {

            if((value[i]<=value[j])&&(value[j]<=value[i]+d))
                c[j]=0;
            if((check[value[j]]==1)&&(value[i]==value[j])&&(j<i))
                c[j]=1;
        }
        ans+=dfs(G,c,pi,i);
        check[value[i]]=1;
        ans%=mod;
    }    
    cout<<ans<<endl;
}