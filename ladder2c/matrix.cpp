#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a;
    cin>>a;
    string s;
    cin>>s;
    ll arr[s.size()];
    for(ll i=0;i<s.size();i++)
    {
        arr[i]=s[i]-'0';
    }
    ll prefix[s.size()+1];
    prefix[0]=0;
    for(ll i=1;i<=s.size();i++)
    {
        prefix[i]=prefix[i-1]+arr[i-1];
    }
    ll x=sqrt(a);
    map <ll,ll> m;
    for(ll i=1;i<=x;i++)
    {
        if(a%i==0)
        {
            m[i]=0;
            m[x/i]=0;
        }
    }
    ll special=0;
    for(ll i=0;i<s.size();i++)
    {
        for(ll j=i+1;j<=s.size();j++)
        {
            if((prefix[j]-prefix[i]>0)&&(a!=0))
            {
                if(a%(prefix[j]-prefix[i])==0)
                {
                    m[prefix[j]-prefix[i]]++;
                }
            }
            else if((a==0)&&(prefix[j]-prefix[i]==0))
            {
                special+=1;
            }
        }
    }
    if(a==0)
    {
        cout<<2*special*(((s.size())*(s.size()+1))/2)-special*special<<endl;
        return 0;
    }
    ll ans=0;
    for(ll i=1;i<=x;i++)
    {
        if(a%i==0)
        {
            ans=ans+m[i]*m[a/i];
        }
    }
    ans=2*ans;
    if(x==sqrt(a))
    {
        ans-=m[x]*m[x];
    }
    cout<<ans<<endl;
}