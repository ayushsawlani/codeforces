#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main()
{
 cin.tie(0);
ios::sync_with_stdio(0);
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector <ll> factors;
    ll x=sqrt(n);
    for(int i=1;i<=x;i++)
    {
        if((n%i==0)&&((n/i)>=3))
        {
            factors.push_back(i);
            if(i>=3)
                factors.push_back(n/i);
        }
    }
    for(int j=0;j<factors.size();j++)
    {
        ll c[factors[j]];
        memset(c,0,factors[j]*sizeof(ll));
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                c[i%factors[j]]=1;
            }
        }
        for(int i=0;i<factors[j];i++)
        {
            if(c[i]==0)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}