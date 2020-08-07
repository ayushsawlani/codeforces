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
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
ll bin(ve <ll> &pre, ll l, ll x)
{
    ll n=sz(pre);
    ll i=l;
    ll j=n-1;
    ll sum=0;
    if(l>0)
        sum=pre[l-1];
    while(i<j)
    {
        ll mid=(i+j)/2;
        if(pre[mid]-sum>=x)
        {
            j=mid;
        }
        else
        {
            i=mid+1;
        }
    }
    if(pre[i]-sum==x)
    {
        return i;
    }
    return inf;
}
int main()
{
    fastio
    ll n;
    cin>>n;
    ve <ll> in(n);
    inarr(i, in, n);
    ve <ll> pre1(n, 0), pre2(n, 0);
    fr(i, 0, n-1)
    {
        pre1[i]=i>0?pre1[i-1]:0;
        pre2[i]=i>0?pre2[i-1]:0;
        if(in[i]==1)
        {
            pre1[i]++;
        }
        else
        {
            pre2[i]++;
        }
    }
    ve <pair <ll,ll>> ans;
    fr(i, 1, n)
    {
        ll c1=0, c2=0;
        ll j=-1;
        ll x1=-1;
        while(j<n-1)
        {
            ll r1=bin(pre1, j+1, i), r2=bin(pre2, j+1, i);
            if(r1<r2)
            {
                c1++;
                x1=1;
            }
            else
            {
                c2++;
                x1=2;
            }
            j=min(r1, r2);
        }
        if((j==n-1)&&(c1!=c2))
        {
            if(((c1>c2)&&(x1==1))||((c2>c1)&&(x1==2)))
            {
                ans.pb(mk(max(c1, c2), i));
            }
        }
    }
    sort(all(ans));
    cout<<sz(ans)<<endl;
    fr(i, 0, sz(ans)-1)
    {
        cout<<ans[i].fi<<" "<<ans[i].se<<endl;
    }
}