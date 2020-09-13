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
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
ll gcd(ll a,ll b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
ll solve(ll a,ll b,ll x, ll num, ve <ll> &util)
{
    ll lcm=(a*b)/gcd(a,b);
    ll ans=0;
    ans+=(num*((x)/lcm));
    ans+=util[(x)%lcm];
    return ans;
}
int main()
{
    fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll a, b, q;
        cin>>a>>b>>q;
        ll lcm=(a*b)/gcd(a, b);
        if(a<b)
        {
            ll _t;
            swap(a,b,_t);
        }
        ll num=0;
        ve <ll> util(lcm);
        fr(i, 0, lcm-1)
        {
            if((i%a)%b!=i%b)
                num++;
            util[i]=num;
        }
        fr(t1, 0, q-1)
        {
            ll l,r;
            cin>>l>>r;
            cout<<solve(a,b,r, num, util)-solve(a,b,l-1,num, util)<<endl;
        }
    }
}