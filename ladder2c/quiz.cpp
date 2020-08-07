#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000009
long long int fast_expo(ll a, ll n)
{
	ll ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=((ans*a)%M);
		a=((a*a)%M);
		n=n/2;
	}
	return ans;
}
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    ll total=((k-1)*(n/k)+n%k);
    //cout<<total<<endl;
    if(total>=m)
    {
        cout<<m<<endl;
    }
    else
    {
        ll cont=((m-total)*k);
        ll ans=(m-cont);
        ans=(ans+k*((fast_expo(2,m-total+1)-2+M)%M)%M)%M;
        cout<<ans<<endl;
    }
    /*ll ans2=0;
    for(ll i=0,x=0;i<n;i++,x=(x+1)%k)
    {
        ans2=(ans2+1)%M;
        if(x==k-1)
            ans2=(2*ans2)%M;
    }
    cout<<ans2<<endl;
    */
    
}