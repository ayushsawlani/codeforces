#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include <bits/stdc++.h>
using namespace std;
#define ll long int
#define M 1000000007
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t;
    scanf("%ld",&t);
    while(t--)
    {
        ll temp=-1;
        ll n;
        scanf("%ld",&n);
        ll mons_power[n];
        for(ll i=0;i<n;i++)
        {
            scanf("%ld",&mons_power[i]);
            temp=max(temp,mons_power[i]);
        }
        ll m;
        scanf("%ld",&m);
        pair <ll,ll> hero[m];
        for(ll i=0;i<m;i++)
        {
            scanf("%ld",&hero[i].first);
            scanf("%ld",&hero[i].second);
        }
        sort(hero,hero+m);
        ll m1=hero[0].second;
        vector <pair <ll,ll>> hero_imp;
        for(ll i=0;i<m-1;i++)
        {
            if(hero[i+1].first==hero[i].first)
            {
                m1=max(m1,hero[i+1].second);
            }
            else
            {
                hero_imp.push_back(pair <ll,ll>(hero[i].first,m1));
                m1=hero[i+1].second;
            }
        }
        hero_imp.push_back(pair <ll,ll>(hero[m-1].first,m1));
        set <pair <ll,ll>> hero_imp_imp;
        m1=-1;
        if(hero_imp.size()!=0)
        {
            ll size = hero_imp.size()-1;
            m1=hero_imp[size].second;
            hero_imp_imp.insert(hero_imp[size]);
        }
        for(ll i=(ll)hero_imp.size()-2;i>=0;i--)
        {
            if(hero_imp[i].second>m1)
            {
                pair <ll,ll> to_push=hero_imp[i];
                hero_imp_imp.insert(to_push);
            }
            m1=max(hero_imp[i].second,m1);
        }
        if(hero_imp[hero_imp.size()-1].first<temp)
        {
            printf("-1\n");
            continue;
        }
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            m1=mons_power[i];
            for(ll j=i;j<n;j++)
            {
                m1=max(mons_power[j],m1);
                pair <ll,ll> sea(m1,-1);
                auto it=hero_imp_imp.lower_bound(sea);
                if((*it).second<j-i+1)
                {
                    i=j-1;
                    ans++;
                    break;
                }
            }
        }
        printf("%ld\n",ans+1);
    }
}