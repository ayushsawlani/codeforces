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
bool cycle_detection(vector <vector <ll>> &G, ll seed, ve <ll> &c,ve <ll> &cutil)//c and cutil initially 0,seed is any vertex in graph
{
    c[seed]=1;
    cutil[seed]=1;
    for(auto it=G[seed].begin();it!=G[seed].end();it++)
    {
        if(c[*it])
        {
            if(cutil[*it])
                return true;
        }
        else
        {
            if(cycle_detection(G,(*it),c,cutil))
                return true;   
        }
    }
    cutil[seed]=0;
    return false;
}
void dfs(vector <vector <ll>> &G, vector <ll> &c,vector <ll> &pi, ll seed,vector <ll> &topsorted )
{
    c[seed]=1;
    for(auto i=G[seed].begin();i!=G[seed].end();i++)
    {
        if(pi[seed]!=(*i))
            pi[(*i)]=seed;
        if(!(c[(*i)]))
        {
            dfs(G,c,pi,(*i),topsorted);
        }   
    }
    topsorted.push_back(seed);
}
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll m;
        cin>>m;
        ve <ve <ll>> G(n), Gu(n);
        ve <pair <ll, ll>> arr;
        ve <pair <ll, ll>> ans;
        fr(i, 0, m-1)
        {
            ll ty;
            cin>>ty;
            ll a, b;
            cin>>a>>b;
            a--;
            b--;
            if(ty)
            {
                ans.pb(pair <ll,ll> (a+1, b+1));
                G[a].pb(b);
            }
            else
            {
                Gu[a].pb(b);
                Gu[b].pb(a);
            }
        }

        ve <ll> c(n, 0), pi(n, -1), cutil(n, 0);
        ll f=0;
        fr(i, 0, n-1)
        {
            if(c[i]==0)
            {
                if(cycle_detection(G, i, c, cutil))
                {
                    f=1;            
                }
            }
        }
        if(f)
        {
            cout<<"NO"<<endl;
            continue;
        }
        setvector(i, c, 0, n);
        setvector(i, pi, 0, n);
        setvector(i, cutil, 0, n);
        ve <ll> topsorted;
        fr(i, 0, n-1)
        {
            if(c[i]==0)
            {
                dfs(G, c, pi, i, topsorted);
            }
        }
        fr(i, 0, n/2-1)
        {
            ll _t;
            swap(topsorted[i], topsorted[n-i-1], _t);
        }
        //outarr(i, topsorted, n);
        //cout<<endl;
        set <ll> ut;
        //ll c1=0;
        fr(i, 0, n-1)
        {
            ut.insert(topsorted[i]);
            for(auto nei:Gu[topsorted[i]])
            {
                //c1++;
                if(ut.find(nei)==ut.end())
                {
                    ans.pb(pair <ll,ll>(topsorted[i]+1, nei+1));
                }
            }
        }
        //cout<<c1<<endl;
        cout<<"YES"<<endl;
        for(auto pr:ans)
        {
            cout<<pr.fi<<" "<<pr.se<<endl;
        }
    }
}