#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k;
    cin>>n>>k;
    ll c_arr1[101],c_arr2[101];
    for(ll i=0;i<101;i++)
    {
        c_arr1[i]=0;
        c_arr2[i]=0;
    }
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        c_arr1[temp]++;
        c_arr2[temp]++;
    }
    ll ans=0;
    while(c_arr1[k]<n)
    {
        for(ll i=0;i<k;i++)
        {
            if(c_arr1[i]>0)
            {
                c_arr2[i]--;
                c_arr2[i+1]++;
            }
        }
        for(ll i=0;i<101;i++)
            c_arr1[i]=c_arr2[i];
        ans++;
    }
    cout<<ans<<endl;
}