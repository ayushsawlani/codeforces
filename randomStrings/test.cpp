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
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.

ve <ve <ll>> func(ve <ve<ll>> a, ve <ve<ll>> b)
{
    map <ll,ll> c1,pre;
    ll c=0;
    for(auto i: b)
    {
        for(auto j: i)
        {
            c1[j]=c;
            pre[j]=0;
        }
        c++;
    }
    ve <pair <ll,ll>> imp;
    ve <ve <ll>> ans;
    for(auto i: a)
    {
        for(auto j:i)
        {
            if(c1.find(j)!=c1.end())
                imp.pb(pair <ll,ll> (c1[j],j));
            else
            {
                imp.pb(pair <ll,ll> (c, j));
            }
            pre[j]=1;
        }
        sort(imp.begin(), imp.end());
        ve <ll> temp;
        temp.pb(imp[0].se);
        fr(k, 0, sz(imp)-2)
        {
            if(imp[k].fi!=imp[k+1].fi)
            {
                if(sz(temp))
                    ans.pb(temp);
                temp.clear();
            }
            temp.pb(imp[k+1].se);
        }
        if(sz(temp))
            ans.pb(temp);
    }
    for(auto i:b)
    {
        ve<ll> temp;
        for(auto j: i)
        {
            if(pre[j]==0)
            {
                temp.pb(j);
            }
        }
        if(sz(temp))
        {
            ans.pb(temp);
        }
    }
    return ans;
}
int main()
{
    //fastio
    ve <ve <ll> > inp1(1, ve<ll>(2));
    ve <ve <ll> > inp2(1, ve<ll>(2));
    inp1[0]={1,2};
    inp2[0]={2, 3};
    ve <ve <ll>> output=func(inp1, inp2);
    for(auto j:output)
    {
        outarr(i, j, sz(j));
        cout<<endl;
    }
}