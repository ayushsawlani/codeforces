#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main()
{
 cin.tie(0);
ios::sync_with_stdio(0);
    ll a[3];
    for(ll i=0;i<3;i++)
    {
        cin>>a[i];
    }
    sort(a,a+3);
    if(a[2]>2*(a[1]+a[0]))
    {
        cout<<a[1]+a[0]<<endl;
    }
    else
    {
        cout<<(a[1]+a[2]+a[0])/3<<endl;
    }
}