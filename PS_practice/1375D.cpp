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
ll mex(ve <ll> in)
{
    ll n=sz(in);
    ve <ll> cou(n+1, 0);
    fr(i, 0, n-1)
    {
        cou[in[i]]++;
    }
    ll ans=inf;
    fr(i, 0, n)
    {
        if(cou[i]==0)
            ans=min(ans, (ll)i);
    }
    return ans;
}
bool func(ve <ll> in, ll pos)
{
    ll x=mex(in);
    ll c=2*sz(in);
    while(c--)
    {
        outarr(i, in, sz(in));
        cout<<endl;
        ll _t;
        if(x<pos)
        {
            swap(in[x], x, _t);   
        }
        else if(x>pos)
        {
            swap(in[x-1], x, _t);
        }
        else
        {
            break;
        }
    }
    fr(i, 0, sz(in)-2)
    {
        if(in[i]>in[i+1])
            return false;
    }
    return true;
}
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ve <ll> ans;
        ll n;
        cin>>n;
        ve <ll> in(n);
        ve <ll> upd(n, false);
        inarr(i, in, n);
        while(1)
        {
            ll f=1;
            fr(i, 0, n-2)
            {
                if(in[i]>in[i+1])
                    f=0;
            }
            if(f)
                break;
            ll x=mex(in);
            if(x<n)
            {
                in[x]=x;
                ans.pb(x+1);
                upd[x]=true;
            }
            else
            {
                fr(i, 0, n-1)
                {
                    if(upd[i]==false)
                    {
                        ans.pb(i+1);
                        in[i]=n;
                        break;
                    }
                }
            }
        }
       cout<<sz(ans)<<endl;
        outarr(i, ans, sz(ans));
        cout<<endl;
    }

}