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
int main()
{
    //fastio
    ll t;
    cin>>t;
    ve <ll> fun(67), pre(67);
    fun[1]=1;
    pre[1]=1;
    fr(i, 2, 63)
    {
        fun[i]=pre[i-1]+i;
        pre[i]=pre[i-1]+fun[i];
    }
    while(t--)
    {
        ll n;
        cin>>n;
        ve <ll> bits;
        while(n>0)
        {
            bits.pb(n%2);
            n=n/2;
        }
        ll ans=0;
        frn(i, sz(bits)-1, 0)
        {
            if(bits[i])
            {
                ans+=(fun[i+1]);
            }
        }
        //*/
        cout<<ans<<endl;
    }
}