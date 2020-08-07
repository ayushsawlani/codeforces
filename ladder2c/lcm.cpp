#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}

ll lcm(ll a,ll b){
	return (a*b)/gcd(a,b);
}
int main()
{
    ll n;
    cin>>n;
    if(n%2==1)
    {
        if(n>=3)
            cout<<n*(n-1)*(n-2)<<endl;
        else
        {
            cout<<1<<endl;
        }
    }   
    else
    {
        ll ans=1;
        for(ll i=1;i<=n;i++)
        {
            if(n>1)
                ans=max(ans,lcm(n*(n-1),i));   
        }
        ans=max(ans,(n-1)*(n-2)*(n-3));
        cout<<ans<<endl;
    }
    
    
}