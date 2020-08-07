#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000000000 
ll find(ll n1,ll n2,ll n3,ll a,ll b,ll c,ll p1,ll p2,ll p3,ll r,ll i,ll j)
{
    if(i==j)
    {
        return i;
    }
    else
    {
        ll m=(i+j)/2;
        ll price=0;
        ll x=0;
        price+=max(x,p1*(a*m-n1));
        price+=max(x,p2*(b*m-n2));
        price+=max(x,p3*(c*m-n3));
        if(price==r)
            return m;
        else if(price<r)
        {
            return find(n1,n2,n3,a,b,c,p1,p2,p3,r,m+1,j);
        }
        else
            return find(n1,n2,n3,a,b,c,p1,p2,p3,r,i,m);
    }
    
}
int main()
{
    string s;
    cin>>s;
    ll n1,n2,n3,p1,p2,p3,a=0,b=0,c=0,r;
    for(ll i=0;i<s.size();i++)
    {
        if(s[i]=='B')
            a++;
        else if(s[i]=='S')
            b++;
        else
        {
            c++;
        }
    }
    cin>>n1>>n2>>n3>>p1>>p2>>p3>>r;
    ll m=find(n1,n2,n3,a,b,c,p1,p2,p3,r,0,10*M);
    ll price=0;
    ll x=0;
    price+=max(x,p1*(a*m-n1));
    price+=max(x,p2*(b*m-n2));
    price+=max(x,p3*(c*m-n3));
    if(price>r)
        m--;
    cout<<m<<endl;
        
}