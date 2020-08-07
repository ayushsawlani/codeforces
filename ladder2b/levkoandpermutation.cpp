#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,k;
    cin>>n>>k;
    k=n-k;
    if(k==1)
    {
        for(ll i=1;i<n+1;i++)
            cout<<i<<" ";
        cout<<endl;
    }
    else if(k==0)
    {
        cout<<"-1"<<endl;
    }
    else 
    {
        cout<<k<<" ";
        for(ll i=1;i<k;i++)
            cout<<i<<" ";
        for(ll i=k+1;i<n+1;i++)
            cout<<i<<" ";
        cout<<endl;
    }
}