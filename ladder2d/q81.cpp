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
bool dfs(ve <ve <ll>> &G, ve <ll> &c, ll seed)
{
    for(auto j:G[seed])
    {
        if(c[j]==-1)
        {
            c[j]=(c[seed]+1)%2;
            if(dfs(G, c, j)==false)
                return false;
        }
        else
        {
            if(c[j]==c[seed])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    //fastio
    ll n, m;
    cin>>n>>m;
    ve <pair <ll,ll>> in(m);
    fr(i, 0, m-1)
    {
        cin>>in[i].fi>>in[i].se;
    }
    ve <ve <ll>> G(m);
    fr(i, 0, m-1)
    {
        fr(j, 0, m-1)
        {
            ll c=0;
            if((in[i].fi>=min(in[j].fi, in[j].se))&&(in[i].fi<=max(in[j].se, in[j].fi)))
                c++;
            if((in[i].se>=min(in[j].fi, in[j].se))&&(in[i].se<=max(in[j].se, in[j].fi)))
                c++;
            if(c==1)
            {
                c=0;
                if((in[i].fi>min(in[j].fi, in[j].se))&&(in[i].fi<max(in[j].se, in[j].fi)))
                    c++;
                if((in[i].se>min(in[j].fi, in[j].se))&&(in[i].se<max(in[j].se, in[j].fi)))
                    c++;
                if(c==1)
                    G[i].pb(j);
            }
        }
    }
    ve <ll> c(m, -1);
    fr(i, 0, m-1)
    {
        if(c[i]==-1)
        {
            c[i]=1;
            if(dfs(G, c, i)==false)
            {
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    fr(i, 0, m-1)
    {
        if(c[i])
            cout<<"o";
        else
        {
            cout<<"i";
        }
    }
    //*/
}