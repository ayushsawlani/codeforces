#include <bits/stdc++.h> 
using namespace std;
#define ll long long
ll great(ll a,ll b)
{
    while(max(a,b)>0)
    {
        if((a%2==1)&&(b%2==0))
        {
            return 1;
        }
            a=a/2;
            b=b/2;
 
    }
    return 0;
}
#define ll long long
vector <pair <pair <ll,ll>,ll>> compress_array(pair <ll,ll> *a, ll n)
{
    vector <pair <pair <ll,ll>,ll>> ans;
    ll i=0;
    ll c=1;
    ll d=a[0].second;
    while(i<n-1)
    {
        if(a[i].first!=a[i+1].first)
        {
            pair <pair <ll,ll>,ll> temp;
            temp.first.first=a[i].first;
            temp.first.second=d;
            temp.second=c;
            ans.push_back(temp);
            d=a[i+1].second;
            c=1;
        }
        else
        {
            d+=a[i+1].second;
            c++;
        }
        i++;   
    }
    pair <pair <ll,ll>,ll> temp;
    temp.first.first=a[i].first;
    temp.first.second=d;
    temp.second=c;
    ans.push_back(temp);
    c=1;
    return ans;
}
int main()
{
    ll n;
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n;
    ll algo[n],skill[n];
    for(ll i=0;i<n;i++)
    {
        cin>>algo[i];
    }
    for(ll i=0;i<n;i++)
    {
        cin>>skill[i];
    }
    pair <ll,ll> a[n];
    for(ll i=0;i<n;i++)
    {
        a[i].first=algo[i];
        a[i].second=skill[i];
    }
    sort(a,a+n);
    ll ans=0;
    ll count=0;
    vector <pair <pair <ll,ll>,ll>> v=compress_array(a,n);
    for(ll i=0;i<v.size();i++)
    {
        if(v[i].second>1)
        {
            count+=v[i].second;
            ans+=(v[i].first.second);
        }
        else
        {
            ll flag=0;
            for(ll j=0;j<v.size();j++)
            {
                if((!(great(v[i].first.first,v[j].first.first)))&&(i!=j)&&(v[j].second>1))
                    flag=1;
            }
            if(flag==1)
            {
                count++;
                ans+=v[i].first.second;
            }
        }
        
    }
    if(count<2)
        ans=0;
    cout<<ans<<endl;
}