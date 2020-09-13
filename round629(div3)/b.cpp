#include <bits/stdc++.h>
using namespace std;
#define M (ll)(1e9+7)
#define ll long long
ll nc2(ll n)
{
    return  ((n)*(n-1))/2;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll i=2;
        ll j=n;
        ll m;
        while(i<j)
        {
         //   cout<<i<<" "<<j<<endl;
            m=(i+j)/2;
            if(nc2(m)==k)
            {
                break;
            }
            else if(nc2(m)<k)
            {
                i=m+1;
            }
            else
            {
                j=m;
            }
        }
        if(nc2(m)<k)
            m++;
        //cout<<m<<endl;
        for(ll i=0;i<n-m;i++)
        {
            cout<<"a";
        }
        cout<<"b";
        ll m1=nc2(m)-k;
        for(ll i=0;i<m1;i++)
        {
            cout<<"a";
        }
        cout<<"b";
        for(ll i=0;i<n-(n-m+m1+2);i++)
            cout<<"a";
        cout<<endl;
    }
}