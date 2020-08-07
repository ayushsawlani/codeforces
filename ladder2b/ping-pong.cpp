#include <bits/stdc++.h>
using namespace std;
#define ll long long
void bfs(vector <vector<ll>>g,ll *pi,ll s )
{
    ll len_g=g.size();
    queue <ll> q;
    ll c[len_g];
    for(ll i=0;i<len_g;i++)
        c[i]=0;
    q.push(s);
    c[s]=1;
    pi[s]=s;
    while(!(q.empty()))
    {
        ll temp=(q.front());
        q.pop();
        c[temp]=2;
        ll len_temp_adj=g[temp].size();
        for(ll i=0;i<len_temp_adj;i++)
        {
            if(c[g[temp][i]]==0)
            {
                q.push(g[temp][i]);
                c[g[temp][i]]=1;
                pi[g[temp][i]]=temp;
            }
        }
    }
}
int main()
{
    ll n;
    cin>>n;
    vector <vector <ll>> g;
    vector <pair<ll,ll>> v;
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        if(temp==1)
        {
            pair <ll,ll> p;
            cin>>p.first>>p.second;
            v.push_back(p);
            ll len_v=v.size();
            vector <ll> nex;
            g.push_back(nex);
            for(ll i=0;i<len_v-1;i++)
            {
                if(((v[i].first<p.first)&&(p.first<v[i].second))||((v[i].first<p.second)&&(p.second<v[i].second)))
                    g[len_v-1].push_back(i);
                if(((p.first<v[i].first)&&(v[i].first<p.second))||((p.first<v[i].second)&&(v[i].second<p.second)))
                    g[i].push_back(len_v-1);
            }
        }
        if(temp==2)
        {
            ll source,dest;
            cin>>source>>dest;
            source--;
            dest--;
            ll len_v=v.size();
            ll *pi=(ll*)(malloc)(len_v*sizeof(ll));
            for(ll i=0;i<len_v;i++)
            {
                pi[i]=-1;
            }
            bfs(g,pi,source);
            if(pi[dest]==-1)
                cout<<"NO"<<endl;
            else
            {
                cout<<"YES"<<endl;
            }
            
        }
    }
}