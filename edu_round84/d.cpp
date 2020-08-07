#include <bits/stdc++.h>
using namespace std;
#define M (ll)(1e9+7)
#define ll long long
void dfs(vector <vector <ll>> &G,vector <ll> &cycle,vector <ll> &c, ll seed)
{
 //   cout<<"*";
   // cout<<seed<<" ";
    cycle.push_back(seed);
    c[seed]=1;
    if(c[G[seed][0]]==0)
        dfs(G,cycle,c,G[seed][0]);
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector <ll> p(n);
        vector <ll> c(n);
        for(ll i=0;i<n;i++)
        {
            cin>>p[i];
            p[i]--;
        }
        for(ll i=0;i<n;i++)
        {
            cin>>c[i];
        }
        vector <vector <ll>> G(n);
        for(ll i=0;i<n;i++)
        {
            G[i].push_back(p[i]);
            //cout<<i<<" "<<G[i][0]<<endl;
        }
        vector <ll> color(n,0);
        vector <vector <ll>> cycle;
        for(ll i=0;i<n;i++)
        {
            //cout<<color[i]<<endl;
            if(color[i]==0)
            {
                vector <ll> cycle_util;
                dfs(G,cycle_util,color,i);
                //cout<<endl;
                cycle.push_back(cycle_util);
                //cout<<cycle_util.size();
            }
        }
        //cout<<cycle.size()<<endl;
        ll ans=INT64_MAX;
        for(ll i=0;i<cycle.size();i++)
        {
            for(ll j=1;j<=sqrt(cycle[i].size());j++)
            {
                if(cycle[i].size()%j==0)
                {
                    ll f1=j,f2=cycle[i].size()/j;
                    for(ll l=0;l<f1;l++)
                    {
                        ll flag2=0;
                        for(ll k=l;k<cycle[i].size()-f1;k+=f1)
                        {
                            if(c[cycle[i][k]]!=c[cycle[i][k+f1]])
                            {
                                flag2=1;
                                break;
                            }
                        }
                        if(flag2==0)
                        {
                            ans=min(ans,f1);
                            break;
                        }
                    }
                    for(ll l=0;l<f2;l++)
                    {
                        ll flag2=0;
                        for(ll k=l;k<cycle[i].size()-f2;k+=f2)
                        {
                            if(c[cycle[i][k]]!=c[cycle[i][k+f2]])
                            {
                                flag2=1;
                                break;
                            }
                        }
                        if(flag2==0)
                        {
                            ans=min(ans,f2);
                            break;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    
    } 

}