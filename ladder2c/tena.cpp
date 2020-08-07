#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n0,n1;
    cin>>n0>>n1;
    ll arr[2*n0+1];
    for(ll i=0;i<2*n0+1;i++)
    {
        arr[i]=-1;
    }
    for(ll i=1;i<2*n0+1;i=i+2)
    {
        arr[i]=0;
    }
    for(ll i=2;i<2*n0-1;i=i+2)
    {
        arr[i]=1;
        n1=n1-1;
    }
    if(n1<0)
    {
        cout<<-1<<endl;
        return 0;
    }
    ll i=0;
    if(n1>0)
    {
        arr[0]=1;
        n1=n1-1;
        i=i+2;
    }
    if(n1>0)
    {
        arr[2*n0]=1;
        n1=n1-1;
    }
    i=0;
    while((n1>0)&&(i<2*n0+1))
    {
        arr[i]++;
        i=i+2;
        n1=n1-1;
    }
    if(n1>0)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(ll i=0;i<2*n0+1;i++)
    {
        if(arr[i]+1)
        {
            if(arr[i]==1)
                cout<<1;
            else if(arr[i]==2)
            {
                cout<<11;
            }
            else
            {
                cout<<0;
            }
            
        }
    }
    cout<<endl;

}