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
    fastio
    ll n;
    cin>>n;
    ve <pair <ll,ll>> ans;
    fr(i, 0, 2*n+2)
    {
        ans.pb(mk(i, 2));
    }
    if(n%2)
    {
        fr(i, 0, 2*n)
        {
            if(i%2==0)
            {
                ans.pb(mk(i, 1));
            }
            if(i%4!=3)
                ans.pb(mk(i, 0));
        } 
        fr(i, 2, 2*n+2)
        {
            if(i%4!=1)
               ans.pb(mk(i, 4));
            if(i%2==0)
                ans.pb(mk(i, 3));
        }
    }
    else
    {
        n++;
        fr(i, 0, 2*(n))
        {
            if(i%2==0)
            {
                ans.pb(mk(i, 1));
            }
            if(i%4!=3)
                ans.pb(mk(i, 0));
        } 
        fr(i, 2, 2*n-1)
        {
            if(i%4!=1)
               ans.pb(mk(i, 4));
            if(i%2==0)
                ans.pb(mk(i, 3));
        }
        
    }
    cout<<sz(ans)<<endl;
    fr(i, 0, sz(ans)-1)
    {
        cout<<ans[i].fi<<" "<<ans[i].se<<endl;
    }

}