#include <bits/stdc++.h>
using namespace std;
#define M (ll)(1e9+7)
#define ll long long
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n,m,k;
    cin>>n>>m>>k;
    for(ll i=0;i<2*k;i++)
    {
        ll s1,s2;
        cin>>s1>>s2;
    }
    cout<<n*m+m+n-3<<endl;
    for(ll i=0;i<n-1;i++)
    {
        cout<<"U";
    }
    for(ll i=0;i<m-1;i++)
    {
        cout<<"L";
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m-1;j++)
        {
            if(i%2)
                cout<<"L";
            else
            {
                cout<<"R";
            }
        }
        if(i!=n-1)
        cout<<"D";
    }
    cout<<endl;
}