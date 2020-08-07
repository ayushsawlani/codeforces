#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f(ll a,ll b)
{
    if(a==1)
        return b;
    else if(a==0)
        return 0;
    else
    {
        return f(b%a,a)+b/a;
    }
}
int main()
{
    ll a,b;
    cin>>a>>b;
    ll ans=a/b;
    a=(a-((a/b)*b));
    ans+=(f(a,b));
    cout<<ans<<endl;
}