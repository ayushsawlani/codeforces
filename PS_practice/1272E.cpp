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
const ll inf = 9e14;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);

int main()
{
    //fastio
    ll n;
    cin>>n;
    ve <ll> in(n);
    inarr(i, in, n);
    ve <ve <ll>> G(n), revG(n);
    fr(i, 0, n-1)
    {
        if(i+in[i]<n)
        {
            G[i].pb(i+in[i]);
            revG[i+in[i]].pb(i);
        }
        if(i-in[i]>=0)
        {
            G[i].pb(i-in[i]);
            revG[i-in[i]].pb(i);
        }
    }
    queue <ll> q;
    ve <ll> c(n, 0);
    ve <ll> ans1(n, inf);
    fr(i, 0, n-1)
    {
        if(in[i]%2)
        {
            q.push(i);
            c[i]=1;
            ans1[i]=0;
        }
    }
    while(q.empty()==false)
    {
        ll top=q.front();
        q.pop();
        for(auto chi:revG[top])
        {
            if(c[chi]==0)
            {
                q.push(chi);
                ans1[chi]=ans1[top]+1;
                c[chi]=1;
            }
        }
    }
    setvector(i, c, 0, n);
    ve <ll> ans2(n, inf);
    fr(i, 0, n-1)
    {
        if(in[i]%2==0)
        {
            q.push(i);
            c[i]=1;
            ans2[i]=0;
        }
    }
    while(q.empty()==false)
    {
        ll top=q.front();
        q.pop();
        for(auto chi:revG[top])
        {
            if(c[chi]==0)
            {
                q.push(chi);
                ans2[chi]=ans2[top]+1;
                c[chi]=1;
            }
        }
    }
    ve <ll> ans=ans1;
    fr(i, 0, n-1)
    {
        if(in[i]%2)
            ans[i]=ans2[i];
    }
    fr(i, 0, n-1)
    {
        if(ans[i]==inf)
            ans[i]=-1;
    }
    outarr(i, ans, n);
    cout<<endl;
}