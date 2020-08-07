#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,m;
    cin>>n>>m;
    m=2*m;
    ll arr[n+1];
    for(ll i=1;i<n+1;i++)
        arr[i]=0;
    for(int i=0;i<m;i++)
    {
        ll temp;
        cin>>temp;
        arr[temp]++;
    }
    ll x;
    for(int i=1;i<n+1;i++)
    {
        if(arr[i]==0)
        {
            x=i;
            break;
        }
    }
    cout<<n-1<<endl;
    for(int i=1;i<n+1;i++)
    {
        if(i!=x)
            cout<<x<<" "<<i<<endl;
    }
}