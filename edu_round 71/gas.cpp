#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        ll n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        ll ans=a*n;
        ll pillar[n+1];
        for(ll i=0;i<n+1;i++)
            pillar[i]=0;
        for(ll i=1;i<n-1;i++)
        {
            if(s[i]=='1')
            {
                pillar[i]=1;
                pillar[i+1]=1;
            }
        }
        for(ll i=0;i<n+1;i++)
        {
            ans+=((pillar[i]+1)*b);
        }
        for(ll i=0;i<n;i++)
        {
            if(pillar[i]^pillar[i+1])
                ans+=(a);
        }
        ll i=0;
        ll c=1;
        vector <pair <ll,ll>> v;
        while(i<n)
        {
            if(pillar[i]!=pillar[i+1])
            {
                pair <ll,ll> temp;
                temp.first=pillar[i];
                temp.second=c;
                v.push_back(temp);
                c=1;
            }
            else
            {
                c++;
            }
            i++;           
        }
        pair <ll,ll> temp;
        temp.first=pillar[i];
        temp.second=c;
        v.push_back(temp);
        for(ll i=1;i<v.size()-1;i++)
        {
            if(v[i].first==0)
            {
                if((v[i].second)*b<2*a)
                    ans+=((v[i].second)*b-2*a);
            }
        }
        cout<<ans<<endl;
    }
}