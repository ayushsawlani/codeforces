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
int main()
{
    //fastio
    ll n, r1, r2, r3, d;
    cin>>n>>r1>>r2>>r3>>d;
    ve <ll> in(n);
    inarr(i, in, n);
    ve <ll> ut(n, 0);
    ut[n-1]=min(2*d+r1+r2, in[n-1]*r1+r3);
    ut[n-1]=min(ut[n-1], in[n-1]*r1+2*r1+2*d);
    //cout<<ut[n-1]<<endl;
    frn(i, n-2, 0)
    {
        ut[i]=ut[i+1];
        ut[i]+=2*d;
        ll x=min(in[i]*r1+r3, r1+r2);
        x=min(x, in[i]*r1+2*r1);
        ut[i]+=x;
        //cout<<ut[i]<<endl;
    }
    ve <ll> dp1(n, 0), dp2(n, inf), dp3(n, inf);
    dp1[0]=in[0]*r1+r3;
    dp3[0]=min(r1+r2, in[0]*r1+2*r1)+2*d;
    fr(i, 1, n-1)
    {
        ll x=min(dp1[i-1], dp2[i-1]);
        x=min(dp3[i-1], x);
        ll hel=min(r1+r2, in[i]*r1+2*r1);
        dp1[i]=x+d+in[i]*r1+r3;
        dp3[i]=x+3*d+hel;
        dp2[i]=min(dp3[i-1]-2*d, dp2[i-1])+hel+3*d;
    }
    ll ans=ut[0];
    //cout<<ans<<endl;
    fr(i, 1, n-1)
    {
        ll x=min(dp1[i-1], dp2[i-1]);
        x=min(x, dp3[i-1]);
        ans=min(ans, x+ut[i]+d);
     //   cout<<x<<" "<<ut[i]<<endl;
       // cout<<ans<<endl;
    }

    ll x=min(dp1[n-1], dp2[n-1]);
    x=min(dp3[n-1], x);
    ans=min(ans, x);
    cout<<ans<<endl;
}