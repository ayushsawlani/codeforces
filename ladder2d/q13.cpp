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
ll diameter_util(vector <set <ll>> &G, ll seed, ve <ll> &c, ve <ll> &leftover)//call this one first after setting c to 0, and leftover to 0
{
    c[seed]=1;
    ll ans=1;
    for(auto it=G[seed].begin();it!=G[seed].end();it++)
    {
        if(c[*it])
        {
            ans=max(ans,1+leftover[*it]);
        }
        else
        {
            ans=max(ans,1+diameter_util(G,(*it),c,leftover));
        }
    }
    leftover[seed]=ans;
    return ans;
}
ll diameter(vector <set <ll>> &G, ll seed, ve <ll> &c, ve <ll> &leftover, ll traversed)//final is the main answer//pass travered as 0
{
    traversed++;
    c[seed]=1;
    ll ans=traversed;
    for(auto it=G[seed].begin();it!=G[seed].end();it++)
    {
        if(c[*it])
        {
            ans=max(ans,traversed+leftover[*it]);
        }
        else
        {
            ans=max(traversed+diameter(G,seed,c,leftover,traversed),ans);
        }
    }
    return ans;
}
int main()
{
    //fastio
    ll size = 1e5+2;
    ll n;
    cin>>n;
    ve <ll> input(n);
    ve <ll> count(size,0);
    inarr(i,input,n);
    fr(i,0,n)
    {
        count[input[i]]++;
    }
    //cout<<"x"<<endl;
    vector <set <ll>> G(size);
    //cout<<"x"<<endl;
    fr(i,2,size)
    {
        ll parent=0;
        for(ll j=i;j<size;j+=i)
        {
            if(count[j])
            {
                if(parent!=0)
                    G[parent].insert(j);
                parent=j;
            }
        }
    }
    ve <ll> c(size,0),leftover(size,0);
    /*fr(i,0,size)
    {
        if(sz(G[i]))
            cout<<i<<endl;
        outarr(j,G[i],sz(G[i]));
        if(sz(G[i]))
        cout<<endl;
    }*/
    ll i=0;
    ll ans=0;
    while(i<size)
    {
        if(!(c[i]))
        {
            diameter_util(G,i,c,leftover);
        }
        i++;
    }
    fr(i,0,size)
    {
        /*if(sz(G[i]))
            cout<<i<<" "<<leftover[i]<<" "<<sz(G[i])<<endl;
        */
        ans=max(ans,leftover[i]);
    }
    cout<<ans<<endl;
}