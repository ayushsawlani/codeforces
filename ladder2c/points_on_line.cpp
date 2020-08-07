#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,d;
    cin>>n>>d;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll i=0;ll j=0;
    ll sum=0;
    while((j<n)&&(i<n))
    {
        if(a[j]-a[i]>d)
        {
           i++;
        }
        else
        {
            if(j-i+1>=3)
                sum+=((j-i-1)*(j-i)-((j-i)*(j-i-1))/2);
            j++;
        }
    }
        
    cout<<sum<<endl;
}