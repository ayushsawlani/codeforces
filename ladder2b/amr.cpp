#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int r,x1,y1,x2,y2;
    cin>>r>>x1>>y1>>x2>>y2;
    double dist=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    long long int x=dist/(2.0*r);
    if(dist>=2.0*r)
    {
        if(dist/(2.0*r)>x*1.0)
        {
            x+=1; 
        }
        cout<<x<<endl;
    }
    else if(dist>0)
    {
        cout<<1<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
}