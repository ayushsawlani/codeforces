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
int main()
{
    fastio
        ll n,m;
    cin>>n;
    m=n-1;
    vector <vector <ll>> G;
    for(ll i=0;i<n;i++)
    {
        vector <ll> temp;
        G.push_back(temp);
    }
    map<pair <ll,ll>,ll> ind;
    map<pair <ll,ll>,ll> label;
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        ind[pair <ll,ll>(a,b)]=i;
        ind[pair <ll,ll>(b,a)]=i;
        label[pair <ll,ll>(a,b)]=-1;
        label[pair <ll,ll>(b,a)]=-1;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(n==2)
    {
        cout<<0<<endl;
        return 0;
    }
    ve <ll> ans(m,-1);
    pair <ll,ll> x;
    fr(i, 0, n)
    {
        if(sz(G[i])==1)
        {
            x.fi=i;
            x.se=G[i][0];
            label[x]=0;
            x.se=i;
            x.fi=G[i][0];
            label[x]=0;
            break;
        }
    }
    fr(i, 0, n)
    {
        if((sz(G[i])==1))
        {
            x.fi=i;
            x.se=G[i][0];
            if(label[x]==-1)
            {
                label[x]=1;
                x.se=i;
                x.fi=G[i][0];
                label[x]=1;
                break;
            }
        }
    }
    ll flag=0;
    fr(i, 0, n)
    {
        if((sz(G[i])==1))
        {
            x.fi=i;
            x.se=G[i][0];
            if(label[x]==-1)
            {
                label[x]=2;
                x.se=i;
                x.fi=G[i][0];
                label[x]=2;
                flag=1;
                break;
            }
        }
    }
    ll c=3;
    if(flag==0)
        c=2;
    for(auto it=label.begin();it!=label.end();it++)
    {
        if(it->second==-1)
        {
            it->second=c;
            pair <ll,ll> x(it->first.second,it->first.first);
            label[x]=c;
            c++;
        }
    }
    for(auto it=label.begin();it!=label.end();it++)
    {
        pair <ll,ll> ele=it->first;
        ans[ind[ele]]=label[ele];
    }
    outarr(i,ans,m);
    cout<<endl;
}