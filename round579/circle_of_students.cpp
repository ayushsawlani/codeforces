#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        ll n;
        cin>>n;
        ll a[2*n];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll min=a[0],max=a[0];
        for(ll i=0;i<n;i++)
        {
            if(min>a[i])
                min=a[i];
            if(max<a[i])
                max=a[i];
            a[i+n]=a[i];
        }
        ll min_i=0;
        ll max_i=0;
        for(ll i=0;i<n;i++)
        {
            if(a[i]==min)
            {
                min_i=i;
                break;
            }
        }
        for(ll i=0;i<n;i++)
        {
            if(a[i]==max)
            {
                max_i=i;
                break;
            }
        }
        ll flag1=0;
        ll flag2=0;
        for(ll i=min_i;i<min_i+n-1;i++)
        {
            if(a[i+1]<a[i])
            {
                flag1=1;
                break;
            }
        }
        for(ll i=max_i;i<max_i+n-1;i++)
        {
            if(a[i+1]>a[i])
            {
                flag2=1;
                break;
            }
        }
        if((flag1)&&(flag2))
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
        
    }
}