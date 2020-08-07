#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll gcd(ll a,ll b)
{
    if(a%b==0)
        return b;
    else
    {
        return gcd(b,a%b);
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    ll a,b,temp;
    cin>>a;
    for(ll i=0;i<n;i++)
        cin>>temp;
    cin>>b;
    for(ll i=0;i<m;i++)
        cin>>temp;
    if(n>m)
    {
        if(a*b<0)
            cout<<"-Infinity"<<endl;
        else
        {
            cout<<"Infinity"<<endl;
        }
        
    }
    else if(n<m)
    {
        cout<<"0/1"<<endl;   
    }
    else
    {
        ll temp=1;
        if(a<0)
        {
            temp=(-1)*temp;
            a=(-1)*a;
        }
        if(b<0)
        {
            b=(-1)*b;
            temp=(-1)*temp;
        }
        ll x=gcd(a,b);
        a=a/x;
        b=b/x;
        cout<<temp*a<<"/"<<b<<endl;
        
    }
    
    
}