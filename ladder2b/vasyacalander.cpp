#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll d,n;
    cin>>d>>n;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        if(i!=n-1)
            ans+=(d-temp);
    }
    cout<<ans<<endl;
}