#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll distsquare(ll x,ll y)
{
    return x*x+y*y;
}
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    ll x=0;
    ll y=0;
    for(ll i=n-1;i>=0;i--)
    {
        if(i>=n/2)
        {
            x+=a[i];
        }
        else
        {
            y+=a[i];
        }
    }
    cout<<x*x+y*y<<endl;
}