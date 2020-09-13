#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define pb push_back
#define mod 1000000007
#define inarr(i,arr,n); for(ll i=0;i<n;i++) cin >> arr[i];
#define outarr(i,arr,n); for(ll i=0;i<n;i++) cout<<arr[i]<<' ';
#define swap(a,b,t) {t=a;a=b;b=t;}
#define ve vector
#define sz(a) (int)((a).size())
#define fi first
#define se second
#define pa pair
#define fastio  {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define ll long long int
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e14;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
void dfs(vector <vector <ll>> &G,vector <ll> &c,vector <ll> &pi,ve <ll> &setnum,ve <ll> &belong,map <pair <ll,ll>,ll> &wt, ll seed)
{
    setnum[belong[seed]]++;
    c[seed]=1;
    for(auto i=G[seed].begin();i!=G[seed].end();i++)
    {
        if(pi[seed]!=(*i))
            pi[(*i)]=seed;
        if((!(c[(*i)]))&&(wt[pair <ll,ll> (seed, (*i))]==0))
        {
            dfs(G,c,pi,setnum,belong, wt,(*i));
        }   
    }
}
int main()
{
    fastio
        ll n,m,k;
    cin>>n>>m>>k;
    ve <ll> setnum(k);
    inarr(i, setnum, k);
    vector <vector <ll>> G;
    map <pair <ll,ll>,ll> wt;
    for(ll i=0;i<n;i++)
    {
        vector <ll> temp;
        G.push_back(temp);
    }
    for(ll i=0;i<m;i++)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
        if(wt.find(pair <ll,ll>(a, b))!=wt.end())
        {
            wt[pair<ll,ll>(b, a)]=min(w,wt[pair<ll,ll>(b, a)]);
            wt[pair<ll,ll>(a, b)]=min(w,wt[pair<ll,ll>(a, b)]);
        }
        else
        {
            wt[pair <ll,ll>(a,b)]=w;   
            wt[pair <ll,ll>(b,a)]=w;   
        }
        
    }
    ve <ll> belong(n, 0);
    ll j=0;
    fr(i, 0, n)
    {
        while(setnum[j]==0)
            j++;
        belong[i]=j;
        setnum[j]--;
    }
    ve <ve <ll>> collection(k,ve <ll>());
    fr(i, 0, n)
    {
        collection[belong[i]].pb(i);
    }
    ve <ll> c(n,0), pi(n,-1), priority(n,inf);
    fr(i, 0, n)
    {
        fr(j, 0, k)
        {
            if((setnum[j]!=sz(collection[j]))&&(setnum[j]!=0))
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
        if(c[i]==0)
        {
            dfs(G, c, pi, setnum, belong, wt, i);
        }
    }    
    cout<<"Yes"<<endl;
    ve <ve <ll>> ans(k, ve <ll>(k, inf));   
    fr(i, 0, n)
    {
        ans[belong[i]][belong[i]]=0;
        fr(j, 0, sz(G[i]))
        {
            ll ele=G[i][j];
            ans[belong[i]][belong[ele]]=min(ans[belong[i]][belong[ele]], wt[pair<ll,ll>(i, ele)]);
        }
    }

    for (ll l = 0; l < k; l++)  
    {  
        // Pick all vertices as source one by one  
        for (ll i = 0; i < k; i++)  
        {  
            // Pick all vertices as destination for the  
            // above picked source  
            for (j = 0; j < k; j++)  
            {  
                // If vertex k is on the shortest path from  
                // i to j, then update the value of dist[i][j]  
                if (ans[i][l] + ans[l][j] < ans[i][j])  
                    ans[i][j] = ans[i][l] + ans[l][j];  
            }  
        }  
    }
     
    fr(i, 0, k)
    {
        fr(j, 0, k)
        {
            if(ans[i][j]==inf)
                cout<<-1<<" ";
            else
            {
                cout<<ans[i][j]<<" ";   
            }
        }
        cout<<endl;
    } 
}