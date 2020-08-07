#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    ll x=1;
    ll i=0;
    ll ans=0;
    while(i<n-1)
    {
        if(a[i]==a[i+1])
        {
            x++;
        }
        else
        {
            if(x>1)
                ans+=((x*(x+1)))/2;
            else
            {
                ans++;
            }
            
            x=1;
        }
        i++;
        
    }
    if(x>1)
        ans+=((x*(x+1)))/2;
    else
    {
        ans++;
    }
    
    cout<<ans<<endl;
}