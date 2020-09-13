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
    ll n, m;
    cin>>n>>m;
    ve <ve <ll>> in(n, ve <ll> (m));
    fr(i, 0, n-1)
    {
        inarr(j, in[i], m);
    }
    ll ans=0;
    fr(i, 0, m-1)
    {
        map <ll, ll> diff;
        fr(j, 0, n-1)
        {
            ll yo=in[j][i]-i-1-j*m;
            if(diff.find(yo)==diff.end())
            {
                diff[yo]=0;
            }
            diff[yo]++;
        }
        ll ans1=n-diff[0];
        fr(j, 1, n-1)
        {
            diff[in[j-1][i]-i-1-j*m]--;
            ll yo=in[j-1][i]-i-1-(j-1+n)*m;
            if(diff.find(yo)==diff.end())
            {
                diff[yo]=0;
            }
            diff[yo]++;
            ans1=min(ans1, j+n-diff[-j*m]);
        }
        //cout<<ans1<<endl;
        ans+=ans1;
    }
    cout<<ans<<endl;
}