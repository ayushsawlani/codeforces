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
int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ve <ll> in(n);
        inarr(i, in, n);
        ve <ll> ans1, ans2;
        fr(i, 0, n-1)
        {
            if(in[i])
            {
                ans1.pb(1);
            }
            else
            {
                ans2.pb(0);
            }
        }
        if(sz(ans1)>n/2)
        {
            if(sz(ans1)%2)
                ans1.pop_back();
            cout<<sz(ans1)<<endl;
            outarr(i, ans1, sz(ans1));
            cout<<endl;
            continue;
        }
        else
        {
            cout<<sz(ans2)<<endl;
            outarr(i, ans2, sz(ans2));
            cout<<endl;
        }
           
    }
}