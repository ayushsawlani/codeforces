#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    ll ans=0;
    for(ll i=0;i<n;i++)
        cin>>a[i];
    ll x=a[0];
    for(ll i=1;i<n;i++)
        x=gcd(x,a[i]);
    for(ll i=1;i<sqrt(x);i++)
    {
        if(x%i==0)
            ans+=2;
    }
    ll p1=sqrt(x);
    double p2=p1;
    double p3=sqrt(x);
    if(p2==p3)
        ans++;
    cout<<ans<<endl;
}