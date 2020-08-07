#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    double x1,y1,r1,x2,y2,r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    double dist=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    double ans;
    ll m1=max(r1,r2);
    ll m2=min(r1,r2);
    if(dist>=r1+r2)
        ans=(dist-r1-r2)/2.0;
    else if((dist>=m1-m2))
        ans=0;
    else
    {
        ans=(m1-m2-dist)/2.0;
    }
    printf("%f\n",ans);    

}