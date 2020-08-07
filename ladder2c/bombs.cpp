#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;
using std::endl;
using std::ios;
#define ll long long
ll mod(ll x)
{
    if(x<0)
        x=(-1)*x;
    return x;
}
bool greater (pair <ll,ll> &p1, pair <ll,ll> &p2)
{
    return (mod(p1.first)+mod(p1.second)<mod(p2.first)+mod(p2.second));
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    ll n;
    cin>>n;
    ll inst=6*n;
    pair <ll,ll> point[n];
    for(ll i=0;i<n;i++)
    {
        cin>>point[i].first>>point[i].second;
        if(point[i].first==0)
            inst-=2;
        if(point[i].second==0)
            inst-=2;
    }
    sort(point,point+n,greater);
    cout<<inst<<endl;
    for(ll i=0;i<n;i++)
    {
        ll dist1=point[i].first;
        ll dist2=point[i].second;
        if(dist1>0)
        {
            cout<<"1 "<<dist1<<" R"<<endl;
        }
        else if(dist1<0)
        {
            cout<<"1 "<<(-1)*dist1<<" L"<<endl;
        }
        if(dist2>0)
        {
            cout<<"1 "<<dist2<<" U"<<endl;
        }
        else if(dist2<0)
        {
            cout<<"1 "<<(-1)*dist2<<" D"<<endl;
        }
        cout<<2<<endl;
        if(dist1>0)
        {
            cout<<"1 "<<dist1<<" L"<<endl;
        }
        else if(dist1<0)
        {
            cout<<"1 "<<(-1)*dist1<<" R"<<endl;
        }
        if(dist2>0)
        {
            cout<<"1 "<<dist2<<" D"<<endl;
        }
        else if(dist2<0)
        {
            cout<<"1 "<<(-1)*dist2<<" U"<<endl;
        }
        cout<<3<<endl;
    }
}