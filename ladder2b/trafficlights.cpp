#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll l,d,v,g,r;
    cin>>l>>d>>v>>g>>r;
    ll x=d/v;
    double p=(1.0*d)/(1.0*v)-x;
    double t1=0.00;
    if(x%(g+r)>=g)
        t1=(g+r)-(x%(g+r))-p;
    double t=(1.0*l)/(1.0*v);
    t+=t1;
    printf("%f\n",t);
}