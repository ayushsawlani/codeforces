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
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
int main()
{
    //fastio
    ll t; cin>>t;
    while(t--)
    {
        ll n, k;
        cin>>n>>k;
        ve <ll> a(n), b(n);
        inarr(i, a, n);
        inarr(i, b, n);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ll ans=0;
        fr(i, 0, k-1)
        {
            ans+=max(a[i], b[n-1-i]);
        }
        fr(i, k, n-1)
        {
            ans+=a[i];
        }
        cout<<ans<<endl;
    }
}