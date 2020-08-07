#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    pair <ll,ll>a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a,a+n);
    cout<<(n+1)/2<<endl;
    for(ll i=0;i<n;i+=2)
        cout<<a[i].second<<" ";
    cout<<endl;
    cout<<(n)/2<<endl;
    for(ll i=1;i<n;i+=2)
        cout<<a[i].second<<" ";
    cout<<endl;
}