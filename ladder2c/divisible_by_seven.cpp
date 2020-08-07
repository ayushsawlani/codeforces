#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    string s;
    cin>>s;
    ll n=s.size();
    ll a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=(ll)(s[i]-'0');
    }
    ll c[10];
    memset(c,0,10*sizeof(ll));
    c[1]=-1;
    c[8]=-1;
    c[6]=-1;
    c[9]=-1;
    for(ll i=0;i<n;i++)
    {
        c[a[i]]++;
    }
    map <ll,ll> m;
    m[1896%7]=1896;
    m[1869%7]=1869;
    m[1968%7]=1968;
    m[1698%7]=1698;
    m[1986%7]=1986;
    m[9186%7]=9186;
    m[9168%7]=9168;
    m[9618%7]=9618;
    m[6189%7]=6189;
    m[6198%7]=6198;
    m[6918%7]=6918;
    m[1689%7]=1689;
    vector <ll> final;
    for(int i=1;i<10;i++)
    {
        for(int j=0;j<c[i];j++)
        {
            final.push_back(i);
        }
    }
    ll mod=0;
    for(int i=0;i<final.size();i++)
    {
        mod=(mod*10)%7;
        mod=(mod+final[i])%7;
    }
    mod=(mod*10000)%7;
    for(int i=0;i<final.size();i++)
    {
        cout<<final[i];
    }
    cout<<m[(7-mod)%7];
    for(int j=0;j<c[0];j++)
    {
        cout<<0;
    }
    cout<<endl;
}