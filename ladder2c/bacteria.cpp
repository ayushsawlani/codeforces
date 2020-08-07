#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define M 1000000007
ll upperfloor(ld x)
{
    ll x_=x;
    if(x_==x)
        return x_;
    return x_+1;
}
int main()
{
 cin.tie(0);
ios::sync_with_stdio(0);
    ll k,b,n,t;
    cin>>k>>b>>n>>t;
    ll ans;
    if(k!=1)
        ans=max(upperfloor(n+(log((ld)(k+b-1)/(ld)((k-1)*t+b))/log((ld)k))),(ll)0);
    else
    {
        ans=max(upperfloor(n-(((ld)(t-1))/(ld)(b))),(ll)0);
    }
    cout<<ans<<endl;

}