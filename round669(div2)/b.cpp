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
        ve <ll> ans;
        sort(all(in));
        ll g1, g2;
        ans.pb(in[n-1]);
        g1=in[n-1];
        ll _t;
        swap(in[0], in[n-1], _t);
        fr(i, 1, n-1)
        {
            ll min_j=i;
            g2=-inf;
            fr(j, i, n-1)
            {
                if(g2<gcd(g1, in[j]))
                {
                    g2=gcd(g1, in[j]);
                    min_j=j;      
                }
            }
            g1=g2;
            ll _t;
            swap(in[i], in[min_j], _t);
            ans.pb(in[i]);
        }
        outarr(i, ans, n);
        cout<<endl;
    }
}