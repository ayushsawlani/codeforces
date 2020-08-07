#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll flag=0;
    for(ll i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    ll m1=0;
    for(ll i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            m1=i;
            break;
        }
    }
    ll x=a[m1];
    while((a[m1]==x)&&(m1>=0))
        m1--;
    m1++;
    ll m2=n-1;
    for(ll i=n-1;i>0;i--)
    {
        if(a[i]<a[i-1])
        {
            m2=i;
            break;
        }
    }
    x=a[m2];
    while((a[m2]==x)&&(m2<n))
        m2++;
    m2--;
    ll temp=a[m1];
    a[m1]=a[m2];
    a[m2]=temp;
    flag=0;
    for(ll i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
}