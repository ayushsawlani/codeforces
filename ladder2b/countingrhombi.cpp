#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll w,h;
    cin>>w>>h;
    ll x,y;
    if(h%2==0)
    {
        y=(h/2-1)*(h/2)+h/2;
    }
    else
    {
        y=(h/2)*(h/2+1);
    }
    if(w%2==0)
    {
        x=(w/2-1)*(w/2)+w/2;
    }
    else
    {
        x=(w/2)*(w/2+1);
    }
    cout<<x*y<<endl;
}