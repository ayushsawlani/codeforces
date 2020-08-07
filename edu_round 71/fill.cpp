#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    cin>>n>>m;
    ll b[n][m],a[n][m];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            b[i][j]=0;
            cin>>a[i][j];
        }
    }
    vector <pair <ll,ll>> v;
    for(ll i=0;i<n-1;i++)
    {
        for(ll j=0;j<m-1;j++)
        {
            if((a[i][j])&&(a[i][j+1])&&(a[i+1][j])&&(a[i+1][j+1]))
            {
                b[i][j]=1;
                b[i+1][j]=1;
                b[i][j+1]=1;
                b[i+1][j+1]=1;
                v.push_back({i+1,j+1});
            }
        }
    }
    ll flag=0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(a[i][j]!=b[i][j])
                flag=1;
        }
    }
    if(flag)
        cout<<-1<<endl;
    else
    {
        cout<<v.size()<<endl;
        for(ll i=0;i<v.size();i++)
        {
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
    }

    
}