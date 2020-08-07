#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    if(n%2==0)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        ll a[2*n];
        for(ll i=0;i<2*n;i=i+2)
        {
            a[i]=i+1;
            a[(i+n)%(2*n)]=i+2;
        }
        for(ll i=0;i<2*n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }

    
}