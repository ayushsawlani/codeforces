#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
ll foo(ll x)
{
    while(x%2==0)
    {
        x=(x/2)*3;
    }
    return x;
}
int main()
{
 cin.tie(0);
ios::sync_with_stdio(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;
        if(x>=y)
            cout<<"YES"<<endl;
        else if(x==1)
        {
            cout<<"NO"<<endl;
        }
        else if((x==2)||(x==3))
        {
            if(y>3)
                cout<<"NO"<<endl; 
            else 
                cout<<"YES"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
}