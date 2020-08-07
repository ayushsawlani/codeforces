#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    vector <pair <ll,ll>> v;
    for(ll i=0;i<n;i++)
    {
        pair <ll,ll> temp;
        cin>>temp.first>>temp.second;
        v.push_back(temp);
    }
    ll ans=0;
    sort(v.begin(),v.end());
    ll max[n];
    max[0]=v[0].second;
    for(ll i=1;i<n;i++)
    {
        if(v[i].second<max[i-1])
            ans++;
        max[i]=std::max(max[i-1],v[i].second);
    }
    cout<<ans<<endl;
}