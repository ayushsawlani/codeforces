#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
set <ll> indices[26];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    string s1,s2;
    cin>>s1>>s2;
    for(ll i=0;i<s1.size();i++)
    {
        indices[s1[i]-'a'].insert(i);
    }
    ll mp=-1;
    ll ans=1;
    for(ll i=0;i<s2.size();i++)
    {
        auto it=indices[s2[i]-'a'].upper_bound(mp);
        if(it!=indices[s2[i]-'a'].end())
        {
            mp=(*it);
        }
        else
        {
            ans++;
            mp=-1;
            auto it1=indices[s2[i]-'a'].upper_bound(mp);
            if(it1==indices[s2[i]-'a'].end())
            {
                cout<<-1<<endl;
                return 0;
            }
            else
            {
                mp=(*it1);
            }
        }
    }
    cout<<ans<<endl;
}
