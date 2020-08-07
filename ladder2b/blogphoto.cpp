#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    double h,w;
    ll ans1,ans2;
    cin>>h>>w;
    if(h>w)
    {
        ll x1,y1,x2,y2;
        y1=1;
        while(y1<=w)
            y1=2*y1;
        y1=y1/2;
        if(h/y1>1.25)
            x1=y1*1.25;
        else
        {
            x1=h;
        }
        x2=1;
        while((x2<=1.25*w)&&(x2<=h))
            x2=2*x2;
        x2=x2/2;
        if(x2>=0.8*w)
            y2=w;
        else
        {
            y2=1.25*x2;
        }
        if(x2*y2>x1*y1)
        {
            ans1=x2;
            ans2=y2;
        }
        else if(x1*y1>x2*y2)
        {
            ans1=x1;
            ans2=y1;
        }
        else
        {
            if(x1>x2)
            {
                ans1=x1;
                ans2=y1;
            }
            else
            {
                ans1=x2;
                ans2=y2;
            }
            
        }
        
        
        
    }
    else
    {
        ll x1,y1,x2,y2;
        y1=1;
        while(y1<=h)
            y1=2*y1;
        y1=y1/2;
        if(w/y1>1.25)
            x1=y1*1.25;
        else
        {
            x1=w;
        }
        x2=1;
        while((x2<=1.25*h)&&(x2<=w))
            x2=2*x2;
        x2=x2/2;
        if(x2>=0.8*h)
            y2=h;
        else
        {
            y2=1.25*x2;
        }
        if(x2*y2>x1*y1)
        {
            ans1=y2;
            ans2=x2;
        }
        else if(x1*y1>x2*y2)
        {
            ans1=y1;
            ans2=x1;
        }
        else
        {
            if(y1>y2)
            {
                ans1=y1;
                ans2=x1;
            }
            else
            {
                ans1=y2;
                ans2=x2;
            }
            
        }
        
        
        
    }
    printf("%lld %lld\n",ans1,ans2);
}