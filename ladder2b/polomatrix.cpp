#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,m,d;
    cin>>n>>m>>d;
    ll arr[n*m];
    for(ll i=0;i<n*m;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n*m);
    ll ans=INT_MAX;
    int flag1=0;
    for(ll i=0;i<n*m;i++)
    {
        ll sum=0;
        ll flag=0;
        for(ll j=0;j<n*m;j++)
        {
            ll max1=max(arr[j],arr[i]);
            ll min1=min(arr[j],arr[i]);
            if((max1-min1)%d==0)
            {
                sum+=(max1-min1);
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            flag1=1;
            ans=min(ans,sum);
        }
    }
    if(flag1)
        cout<<ans/d<<endl;
    else
    {
        cout<<-1<<endl;
    }
}