#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        ll b[32]={0};
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<32;j++)
            {
                if(a[i]==pow(2,j))
                {
                    b[j]++;
                    break;
                }
            }
        }
        for(ll i=0;i<11;i++)
        {
            b[i+1]+=(b[i]/2);
        }
        if((b[11]>=1))
            cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        
    } 
}