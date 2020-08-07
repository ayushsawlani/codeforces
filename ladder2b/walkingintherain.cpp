#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    ll min=a[0];
    for(ll i=0;i<n;i++)
    {
        ll max=i;
        if(i<n-1)
        {
            if(a[max]<a[i+1])
                max=i+1;
        }
        min=std::min(a[max],min);
        i=max;
    }
    cout<<min<<endl;
}