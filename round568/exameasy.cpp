#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    cin>>n>>m;
    ll arr[n],ans[n];
    cin>>arr[0];
    cout<<0<<" ";
    for(ll i=1;i<n;i++)
    {
        cin>>arr[i];
        sort(arr,arr+i);
        ll sum=arr[i];
        ll j;
        for(j=0;j<i;j++)
        {
            sum+=arr[j];
            if(sum>m)
                break;
        }
        cout<<(i-j)<<" ";
    }
    cout<<endl;
}