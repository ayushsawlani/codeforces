#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,m;
    cin>>n>>m;
    ll a[n],b[m];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    for(ll i=0;i<m;i++)
        cin>>b[i];
    int i=0,j=0;
    while((i<n)&&(j<m))
    {
        if(b[j]>=a[i])
            i++;
        j++;
    }
    cout<<n-i<<endl;
}