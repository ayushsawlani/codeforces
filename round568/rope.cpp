#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll arr[3],d;
    ll ans=0;
    for(ll i=0;i<3;i++)
        cin>>arr[i];
    cin>>d;
    sort(arr,arr+3);
    ll temp1=arr[1]-arr[0];
    ll temp2=arr[2]-arr[1];
    if(temp1<d)
        ans+=(d-temp1);
    if(temp2<d)
        ans+=(d-temp2);
    cout<<ans<<endl;
}