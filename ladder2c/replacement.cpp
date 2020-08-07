#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    pair <ll,ll> a[n];
    for(ll i=0;i<n;i++)
    {
        a[i].second=i;
        cin>>a[i].first;
    }
    sort(a,a+n);
    ll b[n];
    ll flag=0;
    if(a[n-1].first!=1)
    {
        b[0]=1;
    }
    else
    {
        if(n==1)
            b[0]=2;
        else
        {
            b[0]=1;
        }
    }
    for(ll i=1;i<n;i++)
    {
        if(a[i].first!=1)
        {
            b[i]=a[i-1].first;
        }
        else
        {
            if(i<n-1)
            {
                    b[i]=1;
            }
            else
            {
                b[i]=2;
            }
        }
    }
    for(ll i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
}
