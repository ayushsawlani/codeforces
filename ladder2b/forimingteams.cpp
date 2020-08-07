#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll bfs(vector <vector<ll>>g,ll *pi,ll s )
{
    ll ans=0;
    ll len_g=g.size();
    ll f[len_g];
    queue <ll> q;
    ll c[len_g];
    for(ll i=0;i<len_g;i++)
    {
        c[i]=0;
        f[i]=0;
    }
    q.push(s);
    c[s]=1;
    f[s]=-1;
    ans++;
    pi[s]=s;
    while(!(q.empty()))
    {
        ll temp=(q.front());
        q.pop();
        c[temp]=2;
        ll len_temp_adj=g[temp].size();

                for(ll i=0;i<len_temp_adj;i++)
                {
                    if((c[g[temp][i]]==0)&&(g[g[temp][i]].size()!=2))
                    {
                        q.push(g[temp][i]);
                        c[g[temp][i]]=1;
                        ans++;
                        f[g[temp][i]]=(-1)*(f[temp]);
                        pi[g[temp][i]]=temp;
                    }
                    else
                    {
                        if((c[g[temp][i]]==0))
                        {
                            if((f[g[g[temp][i]][0]]==f[g[g[temp][i]][1]])||(c[g[g[temp][i]][0]]==0)||(c[g[g[temp][i]][1]]==0))
                            {
                                q.push(g[temp][i]);
                                c[g[temp][i]]=1;
                                ans++;
                                f[g[temp][i]]=(-1)*(f[temp]);
                                pi[g[temp][i]]=temp;
                            }
                            else
                            {
                                pi[g[temp][i]]=-2;
                            }
                            
                        }
                    }
                    
                }
            
        
        
    }
    return ans;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    pair <ll,ll> a[m];
    for(ll i=0;i<m;i++)
    {
        cin>>a[i].first>>a[i].second;
        a[i].first--;
        a[i].second--;
    }
    vector <vector <ll>> g;
    for(ll i=0;i<n;i++)
    {
        vector <ll> v;
        g.push_back(v);
    }
    for(ll i=0;i<m;i++)
    {
        g[a[i].first].push_back(a[i].second);
        g[a[i].second].push_back(a[i].first);
    }
    ll *pi=(ll *)(malloc(n*sizeof(ll)));
    for(ll i=0;i<n;i++)
        pi[i]=-1;
    ll ans=0;
    while(1)
    {
        ll flag=0,x;
        for(ll i=0;i<n;i++)
        {
            if(pi[i]==-1)
            {
                x=i;
                flag=1;
                break;
            }

        }
        if(flag==0)
            break;

        ans+=(bfs(g,pi,x));
    }
    if(ans%2==1)
        ans--;
    ans=n-ans;
    cout<<ans<<endl;
}