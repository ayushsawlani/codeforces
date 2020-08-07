#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k;
    cin>>n>>k;
    ll x=k-((n-2)/2),y=2*(k-((n-2)/2));
    if(((x<=0)||(y<=0))&&(n>=2))
    {
        cout<<-1<<endl;
        return 0;
    }
    if((n<2))
    {
        if(k==0)
        {
            for(ll i=1;i<=n;i++)
            {
                cout<<i<<" ";
            }
            cout<<endl;       
        }
        else
        {
            cout<<-1<<endl;
        }
        return 0;
        
    }
    cout<<x<<" "<<y<<" ";
    ll flag1=0,flag2=0;
    ll c=0,i=1;
    while((c<n-2)&&(i<=x-1))
    {
        cout<<i<<" ";
        c++;
        i++;
    }
    i=x+1;
    while((c<n-2)&&(i<=y-1))
    {
        cout<<i<<" ";
        c++;
        i++;
    }
    i=y+1;
    while((c<n-2))
    {
        cout<<i<<" ";
        i++;
        c++;
    }
    cout<<endl;
}