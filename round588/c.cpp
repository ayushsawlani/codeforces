#include <bits/stdc++.h> 
using namespace std;
#define ll long long
int main()
{
    //as
    ll n,m;
    cin>>n>>m;
    vector <vector <ll>> G;
    ll deg[n]={0};
    for(ll i=0;i<n;i++)
    {
        vector <ll> temp;
        G.push_back(temp);
    }
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        deg[a]++;
        deg[b]++;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(n<=6)
    {
        cout<<m<<endl;
        return 0;
    }
    ll ans=0;
    for(ll p=0;p<7;p++)
    {
        ll ans_util=m-deg[p];
        ll m1=0;
        for(ll i=0;i<7;i++)
        {
            ll sum=0;
            for(ll j=0;j<G[p].size();j++)
            {
                ll flag=0;
                sum++;
                for(ll k=0;k<G[i].size();k++)
                {
                    if(G[p][j]==G[i][k])
                        flag=1;
                }
                if(flag)
                    sum--;
            }
            m1=max(m1,sum);

        }
        ans_util=ans_util+m1;
        ans=max(ans_util,ans);
    }
    cout<<ans<<endl;
}