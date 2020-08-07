#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 998244353 
int main()
{
    ll n;
    cin>>n;
    vector <pair <ll,ll>> v;
    for(ll i=0;i<n;i++)
    {
        pair <ll,ll> temp;
        v.push_back(temp);
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.begin()+n);
    ll factorial[n+1];
    factorial[1]=1;
    for(ll i=2;i<n+1;i++)
    {
        factorial[i]=((i%M)*(factorial[i-1]%M))%M;
    }
    ll ans=factorial[n];
    ll i=0;
    ll c=1;
    ll x=1;
    while(i<n-1)
    {
        if(v[i].first!=v[i+1].first)
        {
            x=((x%M)*(factorial[c]%M))%M;
            c=1;
        }
        else
        {
            c++;
        }
        i++;
    }
    x=((x%M)*(factorial[c]%M))%M;
    ans=(ans%M-x%M+M)%M;
    for(ll i=0;i<n;i++)
    {
        ll temp=v[i].first;
        v[i].first=v[i].second;
        v[i].second=temp;
    }
    sort(v.begin(),v.begin()+n);
    i=0;
    c=1;
    x=1;
    while(i<n-1)
    {
        if(v[i].first!=v[i+1].first)
        {
            x=((x%M)*(factorial[c]%M))%M;
            c=1;
        }
        else
        {
            c++;
        }
        i++;
    }
    x=((x%M)*(factorial[c]%M))%M;
    ans=(ans%M-x%M+M)%M;
    i=0;
    c=1;
    x=1;
    for(ll i=0;i<n-1;i++)
    {
        if((v[i].second)>(v[i+1].second))
            x=0;
    }
    while(i<n-1)
    {
        if(v[i]!=v[i+1])
        {
            x=((x%M)*(factorial[c]%M))%M;
            c=1;
        }
        else
        {
            c++;
        }
        i++;
        
    }
    x=((x%M)*(factorial[c]%M))%M;
    ans=(ans%M+x%M)%M;
    cout<<ans<<endl;   
}