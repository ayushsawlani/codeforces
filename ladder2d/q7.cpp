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
#define fr(i, a, b); for (int i = a; i < b; i++)
#define frn(i, a, b); for (int i = a; i > b; i--)
#define mk make_pair
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
ll nc2(ll n)
{
    if(n<2)
        return 0;
    return (n*(n-1))/2;
}
int main()
{
    fastio
        ll n,m;
    cin>>n>>m;
    vector <ve <ll>> G,RG;
    for(ll i=0;i<n;i++)
    {
        ve <ll> temp;
        G.push_back(temp);
        RG.push_back(temp);
    }
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].pb(b);
        RG[b].pb(a);
    }
    ll ans=0;
    fr(i,0,n)
    {
        sort(G[i].begin(),G[i].end());
        sort(RG[i].begin(),RG[i].end());
    }
    fr(i,0,n)
    {
        fr(j,0,n)
        {
            if(i!=j)
            {
                ll count=0;
                auto it1=G[i].begin(),it2=RG[j].begin();
                while((it1!=G[i].end())&&(it2!=RG[j].end()))
                {
                    if(*it1>*it2)
                        it2++;
                    else if(*it1<*it2)
                        it1++;
                    else
                    {
                        count++;
                        it1++;
                    }
                }
                ans+=(nc2(count));
            }
        }
    }
    cout<<ans<<endl;
}