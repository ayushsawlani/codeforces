#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
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
int main()
{
   // cin.tie(0);
 //   ios::sync_with_stdio(0);
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll a[s.size()];
        for(ll i=0;i<s.size();i++)
        {
            a[i]=s[i]-'a';
        }
        vector <pair <ll,ll>> v=compress_array(a,s.size());
        ll c[26];
        memset(c,0,26*sizeof(ll));
        for(ll i=0;i<v.size();i++)
        {
            if(v[i].second%2==1)
                c[v[i].first]=1;
        }
        for(ll i=0;i<26;i++)
        {
            if(c[i])
                cout<<(char)(i+(ll)'a');
        }
        cout<<endl;
    }
}