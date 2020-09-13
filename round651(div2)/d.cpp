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
ll func(ll x, ve <ll> &arr)
{
    ll ans1=0;
    ll n=sz(arr);
    fr(i, 0, n-1)
    {
        if(ans1%2==0)
        {
            if(arr[i]<=x)
            {
                ans1++;
            }
            
        }
        else
        {
            ans1++;
        }
    }
    ll ans2=1;
    fr(i, 1, n-1)
    {
        if(ans2%2)
        {
            if(arr[i]<=x)
            {
                ans2++;
            }
        }
        else
        {
            ans2++;
        }
    }
    return max(ans1, ans2);
}
int main()
{
    //fastio
    ll n, k;
    cin>>n>>k;
    ve <ll> in(n);
    inarr(i, in, n);
    ll m1=inf;
    ll m2=-inf;
    fr(i, 0, n-1)
    {
        m1=min(m1, in[i]);
        m2=max(m2, in[i]);
    }
    ll i=m1;
    ll j=m2;
    while(i<j)
    {
        ll mid=(i+j)/2;
        if(func(mid, in)>=k)
        {
            j=mid;
        }
        else
        {
            i=mid+1;
        }
    }
    cout<<i<<endl;
}