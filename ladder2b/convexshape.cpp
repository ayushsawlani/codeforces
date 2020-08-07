#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string ans="YES";
    ll n,m;
    cin>>n>>m;
    ll a[n][m];
    vector <pair <ll,ll>> v;
    for(ll i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(ll j=0;j<m;j++)
        {
            if(s[j]=='W')
                a[i][j]=1;
            else
            {
                pair <ll,ll> p;
                p.first=i;
                p.second=j;
                v.push_back(p);
                a[i][j]=0;
            }
        }
    }
   
    for(auto i=v.begin();i!=v.end();i++)
    {
        for(auto j=i;j!=v.end();j++)
        {
            ll flag1=0,flag2=0;
            ll x=1;
            if(j->first<i->first)
                x=-1;
            ll p=i->first;
            while(p!=j->first)
            {
                if(a[p][i->second])
                    flag1=1;
                p+=((x)*1);
            }
            x=1;
            if(j->second<i->second)
                x=-1;
            p=i->second;
            while(p!=j->second)
            {
                if(a[j->first][p])
                    flag1=1;
                p+=((x)*1);
            }
            x=1;
            if(j->second<i->second)
                x=-1;
            p=i->second;
            while(p!=j->second)
            {
                if(a[i->first][p])
                    flag2=1;
                p+=((x)*1);
            }
            x=1;
            if(j->first<i->first)
                x=-1;
            p=i->first;
            while(p!=j->first)
            {
                if(a[p][j->second])
                    flag2=1;
                p+=((x)*1);
            }
            if((flag1)&&(flag2))
                ans="NO";
        }
    }
    cout<<ans<<endl;
}