#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <pair <char,ll>> compress_array(string a, ll n)
{
    vector <pair <char,ll>> ans;
    ll i=0;
    ll c=1;
    pair <char,ll> temp;
    while(i<n-1)
    {
        if(a[i]!=a[i+1])
        {
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
    temp.first=a[i];
    temp.second=c;
    ans.push_back(temp);
    c=1;
    return ans;
}

int main()
{
    string s;
    cin>>s;
    vector <pair <char,ll>> v1=compress_array(s,s.size());
    ll ans=0;
    for(ll i=0;i<v1.size();i++)
    {
        if(v1[i].second>2)
        {
            v1[i].second=2;
        }
    }
    ll i=1;
    while(i<v1.size())
    {
        if((v1[i].second==2)&&(v1[i-1].second==2))
        {
            v1[i].second=1;
        }
        i++;
    }
    for(ll j=0;j<v1.size();j++)
    {
        for(ll k=0;k<v1[j].second;k++)
        {
            cout<<v1[j].first;
        }
    }
    cout<<endl;
}