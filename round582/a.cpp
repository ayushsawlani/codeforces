#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll ceven=0,codd=0;
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        if(temp%2==0)
            ceven++;
        else
        {
            codd++;
        }
        
    }
    ll ans=min(ceven,codd);
    cout<<ans<<endl;
}