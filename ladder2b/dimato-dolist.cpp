#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,k;
    cin>>n>>k;
    ll arr[k];
    for(ll i=0;i<k;i++)
        arr[i]=0;
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        arr[i%k]+=temp;
    }
    ll min=0;
    for(ll i=1;i<k;i++)
        if(arr[min]>arr[i])
            min=i;
    cout<<min+1<<endl;
}