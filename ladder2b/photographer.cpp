#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,x;
    cin>>n>>x;
    pair <ll,ll>p;
    cin>>p.first>>p.second;
    ll m1=min(p.first,p.second);
    ll m2=max(p.first,p.second);
    p.first=m1;
    p.second=m2;
    ll flag=0;
    for(ll i=1;i<n;i++)
    {
        pair <ll,ll> temp;
        cin>>temp.first>>temp.second;
        m1=min(temp.first,temp.second);
        m2=max(temp.first,temp.second);
        temp.first=m1;
        temp.second=m2;
        p.first=max(p.first,temp.first);
        p.second=min(p.second,temp.second);
        if(p.second<p.first)
        {
            flag=1;
        }

    }
    if(flag==0)
    {
        if((x>=p.first)&&(x<=p.second))
            cout<<0<<endl;
        else if(x>p.second)
        {
            cout<<x-p.second<<endl;   
        }
        else
        {
            cout<<p.first-x<<endl;
        }
        
        
    }
    else
    {
        cout<<-1<<endl;
    }
    
}