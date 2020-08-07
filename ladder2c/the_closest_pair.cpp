#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main()
{
 cin.tie(0);
ios::sync_with_stdio(0);
    ll n,k;
    cin>>n>>k;
    if(k>=(n*(n-1))/2)
    {
        cout<<"no solution";
        return 0;
    }
    for(ll i=0;i<n;i++)
    {
        cout<<0<<" "<<i<<endl;
    }
}