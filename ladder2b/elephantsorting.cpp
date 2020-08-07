#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
    ll n;
    cin>>n;
    ll ans=0,balance=0;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    for(ll i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            if(a[i-1]-a[i]>balance)
                ans+=(a[i-1]-a[i]-balance);
            balance=a[i-1]-a[i];
            a[i]=a[i-1];
        }
        else
        {
            balance =0;
        }
    }
    cout<<ans<<endl;
}