#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    pair <ll,ll> arr[n];
    int ans=0;
    int x=1;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].second;
        cin>>arr[i].first;
    }
    sort(arr,arr+n);
    int i=n-1;
    while((x>0)&&(i>=0))
    {
        ans+=arr[i].second;
        x+=arr[i].first;
        i--;
        x--;
    }
    cout<<ans<<endl;
}