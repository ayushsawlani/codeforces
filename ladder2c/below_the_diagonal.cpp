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
    ll matrix[n][n]={0};
    for(ll i=0;i<n-1;i++)
    {
        ll r,c;
        cin>>r>>c;
        r--;c--;
        matrix[r][c]=1;
    }
    
}