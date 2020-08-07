#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    cin>>n>>m;
    ll t[101];
    for(ll i=0;i<101;i++)
        t[i]=0;
    cout<<"0"<<" ";
    ll temp;
    cin>>temp;
    t[temp]++;
    for(ll i=1;i<n;i++)
    {
        cin>>temp;
        ll sum=temp;
        ll j=0;
        while((sum<=m)&&(j<101))
        {
            sum+=(j*t[j]);
            j++;
        }
        if((j==101)&&(sum<=m))
        {
            cout<<"0"<<" ";
        }
        else
        {
            j--;
            sum-=(j*t[j]);
            ll ans=t[j]-((m-sum)/j);
            for(ll p=j+1;p<101;p++)
                ans+=t[p];
            cout<<ans<<" ";
        }
        t[temp]++;
    }
    cout<<endl;
}