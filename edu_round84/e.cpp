#include <bits/stdc++.h>
using namespace std;
#define M 998244353
#define ll long long
ll fast_expo(ll a, ll n)
{
	int ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=(ans*a)%M;
		a=(a*a)%M;
		n=(n/2)%M;
	}
	return ans;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        if(n==i)
        {
            cout<<10<<endl;
            continue;
        }
        cout<<((2*fast_expo(10,n-i)*9)%M+((n-i-1)*(fast_expo(10,n-i-1)*81)%M))%M<<" ";
    }
}