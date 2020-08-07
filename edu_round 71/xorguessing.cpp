#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    cout<<"? ";
    for(ll i=0;i<100;i++)
    {
        cout<<(i<<7)<<" ";
        fflush(stdout);
    }
    cout<<endl;
    fflush(stdout);
    ll ans=0;
    ll temp1;
    cin>>temp1;
    ll c=0;
    ll x=1;
    while(c<7)
    {
        ans+=((temp1%2)*x);
        x=x*2;
        temp1=temp1/2;
        c++;
    }
    cout<<"? ";
    for(ll i=1;i<101;i++)
    {
        cout<<i<<" ";
        fflush(stdout);
    }
    cout<<endl;
    fflush(stdout);
    ll temp;
    cin>>temp;
    ans+=((temp>>7)<<7);
    cout<<"! "<<ans<<endl;
    fflush(stdout);
}