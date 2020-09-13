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
ll func(ve <ll> &in, ll x)
{
    ll ans=0;
    ll n=(sz(in));
    fr(i, 0, n-1)
    {
        ans+=abs((in[i]-pow(x, i)));
    }
    return ans;
}
int main()
{
    //fastio
    ll t;
    t=1;
    while(t--)
    {
        ll n;
        cin>>n;
        ve <ll> in(n);
        inarr(i, in, n);
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        ll ans=0;
        sort(all(in));
        ll x;
        if(n>1)
            x=pow(inf, 1.0/(n-1));
        else
        {
            x=1;
        }
        ll l=1;
        ll r=x;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            ll val1=func(in, mid-1);
            ll val2=func(in, mid);
            ll val3=func(in, mid+1);
            if((val2<=val3)&&(val2<=val1))
            {
                ans=val2;
                break;                
            }
            else if((val2<val1)&&(val2>val3))
            {
                ans=val2;
                l=mid+1;
            }
            else
            {
                ans=val2;
                r=mid-1;
            }
        }
        cout<<ans<<endl;
    }
}