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
ll nc2(ll n)
{
    return ((n)*(n-1))/2;
}
void dsu_union(ll a, ll b, vector <ll> &c, vector <set <ll>> &s)//pass the component number of edge vertices in place of a and b
{
    ll max=b;
    ll min=a;
    if(s[a].size()>s[b].size())
    {
        max=a;
        min=b;
    }
    if(a==b)
        return ;
    ll size_max=s[max].size();
    ll size_min=s[min].size();
    while(size_min>0)
    {
        auto i=s[min].begin();
        ll x=(*i);
        c[x]=max;
        s[max].insert(x);
        s[min].erase(i);
        size_min--;
        size_max++;
    }
}
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, m;
        ll a, b;
        cin>>n>>m>>a>>b;
        a--;
        b--;
        ve <ve <ll>> G(n);
        ve <pair <ll,ll>> edgelist;
        fr(i, 0, m-1)
        {
            ll c1, c2;
            cin>>c1>>c2;
            c1--;
            c2--;
            G[c1].pb(c2);
            G[c2].pb(c1);
            edgelist.pb(pair <ll, ll>(c1, c2));
        }
        ve <set <ll>> s(n);
        ve <ll> c(n);
        fr(i, 0, n-1)
        {
            c[i]=i;
            s[i].insert(i);
        }
        fr(i, 0, m-1)
        {
            ll c1=edgelist[i].fi;
            ll c2=edgelist[i].se;
            if((c1!=a)&&(c2!=a)&&(c1!=b)&&(c2!=b))
            {
                dsu_union(c[c1], c[c2], c, s);
            }
        }
        set <ll> s1, s2;
        for(auto neigh:G[a])
        {
            if(neigh!=b)
                s1.insert(c[neigh]);
        }
        for(auto neigh:G[b])
        {
            if(neigh!=a)
                s2.insert(c[neigh]);
        }
        ll c1=0, c2=0;
        for(auto comp:s1)
        {
            if(s2.find(comp)==s2.end())
                c1+=sz(s[comp]);
        }
        for(auto comp:s2)
        {
            if(s1.find(comp)==s1.end())
                c2+=sz(s[comp]);
        }
        //cout<<c1<<" "<<c2<<endl;
        cout<<c1*c2<<endl;
    }

}