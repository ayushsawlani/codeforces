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
        if(a[i]!=a[i+1]+1)
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
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        ll h,n;
        cin>>h>>n;
        ll p[n];
        for(ll i=0;i<n;i++)
        {
            cin>>p[i];
        }
        vector <pair <ll,ll>> v=compress_array(p,n);
        ll ans=0;
        ll carry=0;
        for(ll i=0;i<v.size();i++)
        {
            if((v[i].second+carry)%2==0)
            {
                if(v[i].first!=1)
                    ans++;
            }
            carry=1;
        }
        cout<<ans<<endl;
    }
}