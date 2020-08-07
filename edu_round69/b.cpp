#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    ll max_i=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(ll i=0;i<n;i++)
    {
        if(a[max_i]<a[i])
            max_i=i;
    }
    for(ll i=1;i<=max_i;i++)
    {
        if(a[i-1]>=a[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    for(ll i=n-2;i>=max_i;i--)
    {
        if(a[i+1]>=a[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}