#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    cin>>n;
    ll m1=0,m2=0; 
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        if(m1<temp)
            m1=temp;
    }
    cin>>m;
    for(ll i=0;i<m;i++)
    {
        ll temp;
        cin>>temp;
        if(m2<temp)
            m2=temp;
    }
    cout<<m1<<" "<<m2<<endl;
}