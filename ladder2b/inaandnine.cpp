#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s;
    cin>>s;
    ll a[100001];
    ll len_a=s.size();
    for(ll i=0;i<len_a;i++)
        a[i]=(ll)(s[i])-48;
    ll i=0,j=0;
    ll sum=0;
    vector <pair <ll,ll>> v;
    while(j<len_a)
    {
        if((sum==9))
        {
            pair <ll,ll> p;
            p.first=i;
            p.second=j;
            if(j-i==2)
                v.push_back(p);
            sum-=a[i];
            i++;
        }
        else if(sum<9)
        {
            sum+=a[j++];
        }
        else
        {
            sum-=a[i];
            i++;
        }
    }

    if(sum==9)
        {
            pair <ll,ll> p;
            p.first=i;
            p.second=j;
            v.push_back(p);
        }
    ll len_v=v.size();
    ll x=1;
    ll flag=0;
    ll ans=1;
    for(ll i=0;i<len_v-1;i++)
    {
        if(v[i].second==v[i+1].first+1)
        {
            x++;
        }
        else
        {
            if(x%2==0)
                ans=ans*((x+2)/2);
            while((v[i].second!=v[i+1].first+1)&&(i<len_v-1))
                i++;
            i--;
            x=1;
        }
    }
    if(x%2==0)
        ans=(ans)*((x+2)/2); 
    cout<<ans<<endl;
}