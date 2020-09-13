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
ll sum;
ll gcd(ll a,ll b)
{
    if(a%b==0)
        return b;
    else
    {
        return gcd(b, a%b);
    }
}
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
ll dfs1(ve <ve <ll>> &G, ve <ll> &c, ve <ll> &pi, ve<ll> &num,ve <ll>  &leaf, ll seed)
{
    //cout<<seed<<" ";
    c[seed]=1;
    ll lcm=1;
    for(auto neigh:G[seed])
    {
        if(c[neigh]==0)
        {
            pi[neigh]=seed;
            if(dfs1(G, c, pi, num, leaf, neigh))
                return 1;
        }
    }
    ll cou=0;
    ll m1=-1;
    for(auto neigh:G[seed])
    {
        if(neigh!=pi[seed])
        {
            lcm=((lcm*num[neigh])/gcd(lcm, num[neigh]));
            cou++;
        }
    }
    num[seed]=max(cou*lcm, num[seed]);
    if(cou==0)
    {
        leaf.pb(seed);
    }
    if(lcm>sum)
        return 1; 
    return 0;
}
void dfs2(ve <ve <ll>> &G, ve <ll> &c, ve <ll> &pi, ve<ll> &num, ll seed)
{
    //cout<<seed<<" ";
    c[seed]=1;
    ll cou=sz(G[seed])-1;
    if(seed==0)
        cou++;
    for(auto neigh:G[seed])
    {
        if(c[neigh]==0)
        {
            num[neigh]=num[seed]/cou;
            dfs2(G, c, pi, num, neigh);
        }
    }
}
int main()
{
    //fastio
    ll n;
    cin>>n;
    ll m=n-1;
    ve <ve <ll>> G(n, ve <ll>());
    ve <ll> app(n);
    inarr(i, app, n);
    fr(i, 0, n-1)
    {
        sum+=app[i];
    }
    fr(i, 0, m-1)
    {
        ll a, b;
        cin>>a>>b;
        a--;
        b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    ve <ll> c(n, 0), pi(n, -1), num(n, 1);
    ve <ll> leaf;
    if(dfs1(G, c, pi, num, leaf, 0)==1)
    {
        cout<<sum<<endl;
        return 0;
    }
    setvector(i, c, 0, n);
    setvector(i, pi, -1, n);
    dfs2(G, c, pi, num, 0);
    ll m2=inf;
    for(auto i: leaf)
    {
        m2=min(app[i]/num[i], m2);
        //scout<<i+1<<" "<<num[i]<<endl;
    }
    cout<<sum-m2*num[0]<<endl;
    //*/
}