#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PI 3.14159265359
long double angle(ld x, ld y)
{
    long double ans;
    if(x!=0)
        ans=atan(abs(y)/abs(x));
    else
    {
        ans=PI/2;//hgdhsa
    }
    if((x<0)&&(y<0))
    {
        ans+=PI;
    }
    else if(x<0)
    {
        ans=(-1)*ans;
        ans+=PI;
    }
    else if(y<0)
    {
        ans=(-1)*ans;
        ans+=PI*2;
    }
    return ans;
}
ld diff(ld a,ld b)
{
    if(a>=b)
        return a-b;
    else
    {
        b-=360;
        return a-b;
    }
}
int main()
{
    ld ans=360;
    ll n;
    cin>>n;
    pair <ld,ld> p[n];
    vector <ld> v;
    for(ll i=0;i<n;i++)
    {
        ld x,y;
        cin>>x>>y;
        v.push_back((angle(x,y)*360)/(2*PI));
    }
    sort(v.begin(),v.end());
    if(n==1)
    {
        cout<<0.00000<<endl;
        return 0;
    }
    for(ll i=0;i<n;i++)
    {
        ll prev=(i-1+v.size())%v.size();
        ll next=(i+1)%v.size();
        ans=min(ans,min(360-diff(v[i],v[prev]),360-diff(v[next],v[i])));
        if(v.size()==2)
            ans=min(ans,min(diff(v[i],v[prev]),diff(v[next],v[i])));
    }
    if(ans==360)
        ans=0;
    printf("%Lf\n",ans);
}