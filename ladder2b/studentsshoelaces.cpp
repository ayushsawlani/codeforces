#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m,ans=0;
    cin>>n>>m;
    pair <ll,ll> a[m];
    ll flag[m];
    for(ll i=0;i<m;i++)
    {
        cin>>a[i].first>>a[i].second;
        a[i].first--;
        a[i].second--;
        flag[i]=0;
    }
    while(1)
    {
        ll flagx=0;
        ll freq[n];
        ll one[n];
        ll one_c=0;
        for(ll i=0;i<n;i++)
            freq[i]=0;
        for(ll i=0;i<m;i++)
        {
            if(flag[i]==0)
            {
                freq[a[i].first]++;
                freq[a[i].second]++;
                flagx=1;
            }
        }
        /*for(ll i=0;i<n;i++)
            cout<<freq[i]<<" ";
        cout<<endl;*/
        if(flagx==0)
            break;
        for(ll i=0;i<n;i++)
        {
            if(freq[i]==1)
                one[one_c++]=i;
        }
        for(ll i=0;i<one_c;i++)
        {
            for(ll j=0;j<m;j++)
            {
                if((one[i]==a[j].first)||(one[i]==a[j].second))
                    flag[j]=1;
            }
        }
        if(one_c>0)
            ans++;
        else
        {
            break;
        }
    }
    cout<<ans<<endl;
}