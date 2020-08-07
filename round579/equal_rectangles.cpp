#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        ll n;
        cin>>n;
        ll a[10001];
        for(ll i=0;i<10001;i++)
            a[i]=0;
        ll max=0,min=10000;
        for(ll i=0;i<4*n;i++)
        {
            ll temp;
            cin>>temp;
            if(max<temp)
                max=temp;
            if(min>temp)
                min=temp;
            a[temp]++;
        }
        ll area=max*min;
        ll flag=0;
        for(ll i=1;i<=max;i++)
        {
            if(a[i]%2==1)
                flag=1;
            if(a[i]!=0)
            {
                if(area%i==0)
                {
                    if(a[area/i]%2==1)
                        flag=1;
                    if(a[i]!=a[area/i])
                        flag=1;
                    if(i==area/i)
                        if(a[i]%4!=0)
                            flag=1;
                }
                else
                {
                    flag=1;
                }
            }
                
        }
        if(flag)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
        }
    }
}