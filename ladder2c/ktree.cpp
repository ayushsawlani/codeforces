#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main()
{
    ll n,k,d;
    cin>>n>>k>>d;
    ll dpk[101]={0};
    dpk[0]=1;
    for(ll i=1;i<101;i++)
    {
        for(ll j=i-1;(j>=0)&&(j>=i-k);j--)
        {
            dpk[i]=(dpk[i]+dpk[j])%M;
        }
    }
    ll dpd[101]={0};
    dpd[0]=1;
    for(ll i=1;i<101;i++)
    {
        for(ll j=i-1;(j>=0)&&(j>=i-(d-1));j--)
        {
            dpd[i]=(dpd[i]+dpd[j])%M;
        }
    }
    cout<<(dpk[n]-dpd[n]+M)%M<<endl;
}