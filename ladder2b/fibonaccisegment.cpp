#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    ll a[n],fa[n];
    for(int i=0;i<n;i++)
    {
        fa[i]=0;
        cin>>a[i];
    }
    for(ll i=2;i<n;i++)
        if(a[i]==a[i-1]+a[i-2])
            fa[i]=1;
    ll i=0;
    ll max=0;
    ll l=0;
    while(i<n)
    {
        if(fa[i])
            l++;
        else
        {
            if(max<l)
                max=l;
            l=0;
        }
        i++;
    }
    if(n==1)
        cout<<1<<endl;
    else
    {
     if(max<l)
        max=l;
    cout<<max+2<<endl;    
    }
    
   
}