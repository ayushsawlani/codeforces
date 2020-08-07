#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
ll fast_expo(ll a, ll n)
{
	ll ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=(ans*a)%M;
		a=(a*a)%M;
		n=n/2;
	}
	return ans;
}
ll fac[1001];
int main()
{
 cin.tie(0);
ios::sync_with_stdio(0);
    fac[0]=1;
    for(ll i=1;i<1001;i++)
    {
        fac[i]=(fac[i-1]*i)%M;
    }
    ll n,m;
    cin>>n>>m;
    ll lights[m];
    for(ll i=0;i<m;i++)
    {
        cin>>lights[i];
    }
    sort(lights,lights+m);
    ll total=n-m;
    vector <ll> a;
    a.push_back(lights[0]-1);
    ll power=0;
    for(ll i=1;i<m;i++)
    {
        power+=max((lights[i]-lights[i-1]-2),(ll)0);
        a.push_back(lights[i]-lights[i-1]-1);
    }
    a.push_back(n-lights[m-1]);
    ll ans=fac[total];
    for(ll i=0;i<a.size();i++)
    {
        ans=(ans*fast_expo(fac[a[i]],M-2))%M;
    }
    ans=(ans*fast_expo(2,power))%M;
    cout<<ans<<endl;
}