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
void func1(ve <ll> &in, ve <ll> &reach, ve <ll> &dp1, ll seed)
{
    ll n=sz(dp1);
    if(seed==n)
    {
        return ;
    }
    else if(dp1[seed]==-1)
    {
        ll yo=reach[seed];
        func1(in, reach, dp1, yo);
        dp1[seed]=(yo-seed)*in[seed];
        if(yo!=n)
        {
            dp1[seed]+=dp1[yo];
        }
    }
}
void func2(ve <ll> &in, ve <ll> &reach, ve <ll> &dp1, ll seed)
{
    if(seed==-1)
    {
        return ;
    }
    else if(dp1[seed]==-1)
    {
        ll yo=reach[seed];
        func1(in, reach, dp1, yo);
        dp1[seed]=(seed-yo)*in[seed];
        if(yo!=-1)
        {
            dp1[seed]+=dp1[yo];
        }
    }
}
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve <ll> in(n);
    inarr(i, in, n);
    ve <ll> stac, nextleast(n, n), prevleast(n, -1);
    fr(i, 0, n-1)
    {
        while(!stac.empty())
        {
            ll top=stac[sz(stac)-1];
            if(in[top]<=in[i])
                break;
            nextleast[top]=i;
            stac.pop_back();
        }
        stac.pb(i);
    }
    stac.clear();
    frn(i, n-1, 0)
    {
        while(!stac.empty())
        {
            ll top=stac[sz(stac)-1];
            if(in[top]<=in[i])
                break;
            prevleast[top]=i;
            stac.pop_back();
        }
        stac.pb(i);
    }
    //outarr(i, nextleast, n);
    //cout<<endl;
    //outarr(i, prevleast, n);
    //cout<<endl;
    ve <ll> dp1(n, -1), dp2(n, -1);
    fr(i, 0, n-1)
    {
        if(dp1[i]==-1)
        {
            func1(in, nextleast, dp1, i);
        }
        if(dp2[i]==-1)
        {
            func2(in, prevleast, dp2, i);
        }
    }
    ll val=0;
    ll piv=-1;
    ve <ll> ans(n, 0);
    fr(i, 0, n-1)
    {
        if(val<dp1[i]+dp2[i]-in[i])
        {
            piv=i;
            val=dp1[i]+dp2[i]-in[i];
        }
    }
    ll i=piv;
    ll tr=piv;
    ans[i]=in[i];
    while((tr<n)&&(i<n))
    {
        if(i==nextleast[tr])
        {
            tr=nextleast[tr];
        }
        else
        {
            ans[i]=in[tr];
            i++;
        }
    }
    i=piv;
    tr=piv;
    while((tr>-1)&&(i>-1))
    {
        if(i==prevleast[tr])
        {
            tr=prevleast[tr];
        }
        else
        {
            ans[i]=in[tr];
            i--;
        }
    }
    outarr(i, ans, n);
    cout<<endl;
}