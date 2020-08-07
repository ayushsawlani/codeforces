#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector <pair <ll,ll>> v;
    ll c=1;
    for(ll i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            for(ll j=1;j<=m;j++)
            {
                pair <ll,ll> temp(i,j);
                v.push_back(temp);
            }
        }
        else
        {
            for(ll j=m;j>0;j--)
            {
                pair <ll,ll> temp(i,j);
                v.push_back(temp);
            }
        }
    }
    ll i=0;
    while(k>1)
    {
        cout<<"2 "<<v[i].first<<" "<<v[i].second<<" "<<v[i+1].first<<" "<<v[i+1].second<<endl;
        i=i+2;
        k--;
    }
    cout<<v.size()-i<<" ";
    while(i<v.size())
    {
        cout<<v[i].first<<" "<<v[i].second<<" ";
        i++;
    }
    cout<<endl;
}