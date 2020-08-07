#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main()
{
 cin.tie(0);
ios::sync_with_stdio(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,x,a,b;
        cin>>n>>x>>a>>b;
        cout<<min(n-1,x+abs(a-b))<<endl;
    }
}