#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main()
{
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n,m;
    cin>>n>>m;
    ll k;
    cin>>k;
    ll c[n*m];
    ll dist[n*m];
    memset(c,0,n*m*sizeof(ll));
    memset(dist,0,n*m*sizeof(ll));
    queue <ll> mainq;
    ll ans;
    for(ll i=0;i<k;i++)
    {
        ll x,y;
        cin>>x>>y;
        x--;y--;
        mainq.push(x*(m)+y);
        c[x*m+y]=1;
        dist[x*m+y]=1;
        ans=x*m+y;
    }
    while(!(mainq.empty()))
    {
        ll tovisit=mainq.front();
        mainq.pop();
        ll x=tovisit/m;
        ll y=tovisit%m;
        if(x>0)
        {
            if(c[(x-1)*m+y]==0)
            {
                mainq.push((x-1)*m+y);
                c[(x-1)*m+y]=1;
                dist[(x-1)*m+y]=dist[x*m+y]+1;
                if(dist[ans]<dist[(x-1)*m+y])
                    ans=(x-1)*m+y;
            }
        }
        if(y>0)
        {
            if(c[x*m+y-1]==0)
            {
                mainq.push(x*m+y-1);
                c[(x)*m+y-1]=1;
                dist[(x)*m+y-1]=dist[x*m+y]+1;
                if(dist[ans]<dist[(x)*m+y-1])
                    ans=(x)*m+y-1;
            }
        }
        if(x<n-1)
        {
            if(c[(x+1)*m+y]==0)
            {
                mainq.push((x+1)*m+y);
                c[(x+1)*m+y]=1;
                dist[(x+1)*m+y]=dist[x*m+y]+1;
                if(dist[ans]<dist[(x+1)*m+y])
                    ans=(x+1)*m+y;
            }
        }
        if(y<m-1)
        {
            if(c[(x)*m+y+1]==0)
            {
                mainq.push((x)*m+y+1);
                c[(x)*m+y+1]=1;
                dist[(x)*m+y+1]=dist[x*m+y]+1;
                if(dist[ans]<dist[(x)*m+y+1])
                    ans=(x)*m+y+1;
 
            }
        }
    }
    cout<<ans/m+1<<" "<<ans%m+1<<endl;
}