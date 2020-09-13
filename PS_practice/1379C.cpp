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
const ll inf = INT64_MAX;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll tar, n;
        cin>>tar>>n;
        ve <pair <ll, ll>> in(n);
        fr(i, 0, n-1)
        {
            cin>>in[i].fi>>in[i].se;
        }
        ll ans=-1;
        sort(all(in));
        ve <ll> cumsum(n+1, 0);
        frn(i, n-1, 0)
        {
            cumsum[i]=cumsum[i+1]+in[i].fi;
        }
        fr(i, 0, n-1)
        {
            ll l=0, r=n-1;
            while(l<r)
            {
                ll m=(l+r)/2;
                if(in[m].fi<=in[i].se)
                {
                    l=m+1;
                }
                else
                {
                    r=m;
                }
            }
            if(in[l].fi<=in[i].se)
            {
                l=n;
            }
            ll tak=max(l, n-tar+1);
            ll a=in[i].fi+cumsum[tak];
            ll b=(tar-(n-tak)-1)*in[i].se;
            if(tak<=i)
            {
                a-=in[i].fi;
                b+=in[i].se;
            }
            ll val=a+b;
            ans=max(ans, val);
        }
        cout<<ans<<endl;
    }
}