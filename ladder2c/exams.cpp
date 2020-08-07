#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    pair <ll,ll> v[n];
    for(ll i=0;i<n;i++)
    {
        pair <ll,ll> p;
        cin>>v[i].first>>v[i].second;
    }
    sort(v,v+n);
    ll current=v[0].second;
    for(ll i=1;i<n;i++)
    {
        if(current>v[i].second)
            current=v[i].first;
        else
        {
            current=v[i].second;
        }
    }
    cout<<current<<endl;
        
}