#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll r,c;
    cin>>r>>c;
    ll a[r][c];
    ll b[r][c];
    for(ll i=0;i<r;i++)
        for(ll j=0;j<c;j++)
            cin>>a[i][j];
    b[0][0]=a[0][0];
    for(ll i=1;i<r;i++)
    {
        b[i][0]=a[i][0]+b[i-1][0];
    }
    for(ll i=1;i<c;i++)
    {
        b[0][i]=b[0][i-1]+a[0][i];
        
        for(ll j=1;j<r;j++)
        {
            if(b[j-1][i]>b[j][i-1])
                b[j][i]=b[j-1][i]+a[j][i];
            else
            {
                b[j][i]=b[j][i-1]+a[j][i];
            }
        }
    }
    for(ll i=0;i<r;i++)
        cout<<b[i][c-1]<<" ";
    cout<<endl;
}