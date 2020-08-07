#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 200001
set <pair <ll,ll>> s[M];
int main()
{
    ll n,k;
    cin>>n>>k;
    
    ll size[M]={0};
    ll c[M]={0};
    ll m[M]={0};
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        ll cost=0;
        while(temp>0)
        {
            if(size[temp]<k)
            {
                c[temp]+=cost;
                pair <ll,ll> p;
                p.first=cost;
                p.second=m[cost];
                m[cost]++;
                s[temp].insert(p);
                size[temp]++;
            }
            else
            {
                auto it=s[temp].end();
                it--;
                if((*it).first>cost)
                {
                    s[temp].erase(it);
                    c[temp]-=((*it).first);
                    pair <ll,ll>p(cost,m[cost]);
                    m[cost]++;
                    s[temp].insert(p);
                    c[temp]+=p.first;
                } 
            }
            temp=temp/2;
            cost++;
        }
        if(size[temp]<k)
        {
            c[temp]+=cost;
            pair <ll,ll> p;
            p.first=cost;
            p.second=m[cost];
            m[cost]++;
            s[temp].insert(p);
            size[temp]++;
        }
        else
        {
            auto it=s[temp].end();
            it--;
            if((*it).first>cost)
            {
                s[temp].erase(it);
                c[temp]-=((*it).first);
                pair <ll,ll>p(cost,m[cost]);
                m[cost]++;
                s[temp].insert(p);
                c[temp]+=p.first;
            } 
        }
    }
    ll max=INT64_MAX;
    for(ll i=0;i<M;i++)
    {
        if((max>c[i])&&(size[i]==k))
        {
            max=c[i];
        }
    }
    cout<<max<<endl;
}