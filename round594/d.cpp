#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    string s;
    cin>>s;
    for(ll i=0;i<n;i++)
    {
        if(s[i]==')')
        {
            a[i]=-1;
        }
        else
        {
            a[i]=1;
        }
    }
    pair <ll,ll> stack[n];
    ll size=1;
    stack[0].first=a[0];
    stack[0].second=0;
    ll i=1;
    while(i<n)
    {
        if((stack[size-1].first==1)&&(a[i]==-1))
        {
            size--;
        }
        else
        {
            stack[size].first=a[i];
            stack[size].second=i;
            size++;
        }
        i++;
    }
    ll x=1,y=1;
    if(size%2==0)
    {
        cout<<0<<endl<<1<<" "<<1<<endl;      
        return 0;
    }
    ll ans=0;
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum==0)
        {
            ans++;
        }
    }
    cout<<ans<<endl<<x<<" "<<y<<endl;
}