#include <bits/stdc++.h> 
using namespace std;
#define ll long long
int main()
{
    ll a[4];
    for(ll i=0;i<4;i++)
    {
        cin>>a[i];
    }
    sort(a,a+4);
    if((a[0]+a[3]==a[1]+a[2])||(a[0]+a[1]+a[2]==a[3]))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
}