#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <pair <ll,ll>> compress_array(ll *a, ll n)
{
    vector <pair <ll,ll>> ans;
    ll i=0;
    ll c=1;
    while(i<n-1)
    {
        if(a[i]!=a[i+1])
        {
            pair <ll,ll> temp;
            temp.first=a[i];
            temp.second=c;
            ans.push_back(temp);
            c=1;
        }
        else
        {
            c++;
        }
        i++;   
    }
    pair <ll,ll> temp;
    temp.first=a[i];
    temp.second=c;
    ans.push_back(temp);
    c=1;
    return ans;
}
ll nc2(ll n)
{
    if(n<=1)
    {
        ll x=0;
        return x;
    }
    else
    {
        return ((n)*(n-1))/2;
    }
    
}
int main()
{

    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll a[s.size()];
    ll len_s=s.size();
    for(ll i=0;i<len_s;i++)
    {
        if(s[i]=='A')
            a[i]=0;
        else
        {
            a[i]=1;
        }
    }   
    ll ans=0;
    vector <pair <ll,ll>> v=compress_array(a,len_s);
    for(ll i=0;i<v.size();i++)
    {
        ans+=(nc2(v[i].second));
    }
    ll sum=0;
    for(ll i=1;i<v.size();i++)
    {
        ans+=((v[i].second-1)*(v[i-1].second-1));
        ans+=((v[i].second)*(sum));
        sum+=v[i-1].second;
    }
    cout<<ans<<endl;
}