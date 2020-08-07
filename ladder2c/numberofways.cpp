#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll a[n],ans=0;
    cin>>a[0];
    for(ll i=1;i<n;i++)
    {
        ll temp;
        cin>>temp;
        a[i]=temp+a[i-1];
    }
    ll sum=a[n-1];
    vector <ll> v1,v2;
    ll flag=0;
    if(sum%3==0)
    {
        for(ll i=0;i<n-1;i++)
        {

            if(a[i]==sum/3)
                v1.push_back(i);
            if(a[i]==(2*sum)/3)
                v2.push_back(i);
        }
        ll i=0,j=0;
        ll len_v1=v1.size();
        ll len_v2=v2.size();
        while((i<len_v1)&&(j<len_v2))
        {
            if(v1[i]<v2[j])
            {
                i++;
                ans+=(len_v2-j);
            }
            else
            {
                j++;
            }
        }
        cout<<ans<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    
}
