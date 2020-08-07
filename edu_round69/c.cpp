#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll b[n-1];
    for(ll i=1;i<n;i++)
    {
        b[i-1]=a[i]-a[i-1];
    }
    sort(b,b+n-1);
    ll sum=0;
    for(ll i=0;i<k-1;i++)
    {
        sum+=(b[n-i-2]);
    }
    cout<<a[n-1]-a[0]-sum<<endl;
}