#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    set <ll> x[n];
    set <ll> G;
    ll r=a[0];
    G.insert(r);
    for(ll i=0;i<n;i++)
    {
        r=r|a[i];
        x[0].insert(r);   
        G.insert(r);
    }
    for(ll i=1;i<n;i++)
    {
        x[i].insert(a[i]);
        G.insert(a[i]);
        for(auto j=x[i-1].begin();j!=x[i-1].end();j++)
        {
            x[i].insert((*j)|a[i]);
            G.insert((*j)|a[i]);
        }
    }
    cout<<G.size()<<endl;
}