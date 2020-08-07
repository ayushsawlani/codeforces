#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int main()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a*d>c*b)
        cout<<(a*d-c*b)/gcd(a*d-c*b,a*d)<<"/"<<a*d/gcd(a*d-c*b,a*d)<<endl;
    else if(a*d<c*b)
    {
        cout<<(b*c-a*d)/gcd(b*c-a*d,b*c)<<"/"<<b*c/gcd(b*c-a*d,b*c)<<endl;
    }
    else
    {
        cout<<"0/1"<<endl;
    }
}