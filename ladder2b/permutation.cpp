#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k;
    cin>>n>>k;
    for(ll i=1;i<=2*k;i+=2)
        cout<<i+1<<" "<<i<<" ";
    for(ll i=2*k+1;i<=2*n;i++)
        cout<<i<<" ";
    cout<<endl;
}