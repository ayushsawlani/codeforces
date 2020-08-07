#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,l,r;
    cin>>n>>l>>r;
    ll x=1;
    ll sumgre=0,sumless=0;
    for(ll i=0;i<l;i++)
    {
        sumless+=x;
        x=x*2;
    }
    sumless+=(n-l);
    x=1;
    for(ll i=0;i<r;i++)
    {
        sumgre+=x;
        x=x*2;
    }
    x=x/2;
    sumgre+=((n-r)*x);
    cout<<sumless<<" "<<sumgre<<endl;
}