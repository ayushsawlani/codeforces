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
ve <ll> fac(103);
ll fast_expo(ll a, ll n)
{
	int ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		n=n/2;
	}
	return ans;
}
ll n_c_r_mod_m(ll n, ll r)
{
    ll ans= ((fac[n]*fast_expo(fac[r],mod-2))%mod);
    ans=((ans*fast_expo(fac[n-r],mod-2))%mod);
    return ans;
}
int main()
{
    //fastio
    fac[0]=1;
    fr(i, 1, 102)
    {
        fac[i]=fac[i-1]*i;
        fac[i]%=mod;
    }
    ll n;
    cin>>n;
    ve <ll> a(10)
    inarr(i, a, 10);
    ve <ve <ll>> dp(n+1, ve <ll>(10,0));
    ve <ve <ll>> dp1(n+1, ve <ll>(10,0));
    ll sum=0;
    fr(i, 0, 9)
    {
        sum+=a[i];
    }
    if(n<sum)
    {
        cout<<0<<endl;
        return 0;
    }
    ll _t=0;
    while((_t<10))
    {
        if(a[_t])
            break;
        dp[0][_t]=1;
        _t++;
    }
    fr(len, 1, n)
    {
        if(len>=a[0])
            dp[len][0]=1;
        fr(j, 1, 9)
        {
            frn(k, len-a[j], 0)
            {
                dp[len][j]+=dp[k][j-1]*n_c_r_mod_m(len, k);
                dp[len][j]%=mod;
            }
        }
    }
    if(a[0])
    {
        a[0]--;
    }
        _t=0;
        while((_t<10))
        {
            if(a[_t])
                break;
            dp1[0][_t]=1;
            _t++;
        }
        fr(len, 1, n)
        {
            if(len>=a[0])
                dp1[len][0]=1;
            fr(j, 1, 9)
            {
                frn(k, len-a[j], 0)
                {
                    dp1[len][j]+=dp1[k][j-1]*n_c_r_mod_m(len, k);
                    dp1[len][j]%=mod;
                }
            }
        }   
    ll ans=0;
    fr(i, sum, n)
    {
        ans+=(dp[i][9]-(i>0?dp1[i-1][9]:1));
        ans+=mod;
        ans%=mod;
    }
    cout<<ans<<endl;
    //*/
}