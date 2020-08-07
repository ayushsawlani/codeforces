#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    ll ans1=0,ans2=0;
    ll i=0;ll j=0;
    ll prefixsum[n+1];
    prefixsum[0]=0;
    for(ll i=1;i<=n;i++)
    {
        prefixsum[i]=prefixsum[i-1]+a[i-1];
    }
    while((j<n)&&(i<n))
    {
        if(a[j]*(j-i+1)-(prefixsum[j+1]-prefixsum[i])>k)
        {
            i++;
        }
        else
        {
            if(j-i+1>ans1)
            {
                ans1=j-i+1;
                ans2=j;
            }
            j++;
        }
    }
    cout<<ans1<<" "<<a[ans2]<<endl;
}