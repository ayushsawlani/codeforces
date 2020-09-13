#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ceil (ll)ceil
#define ll int
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
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
//const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
int main()
{
    ll n, m, t;
    cin>>n>>m>>t;
    ve <ve <ll>>in(n, ve <ll>(m, 0));
    fr(i, 0, n-1)
    {
        string s;
        cin>>s;
        fr(j, 0, m-1)
        {
            in[i][j]=s[j];   
        }
    }
    ve <ve <ll>>final(n, ve <ll>(m, 0));
    ve <ve <ll>>dist(n, ve <ll>(m, -1));
    queue <pair <ll,ll>> q;
    fr(i, 0, n-1)
    {
        fr(j, 0, m-1)
        {
            ll f=0;
            if(i>0)
            {
                if(in[i-1][j]==in[i][j])
                {
                    f=1;
                }
            }
            if(j>0)
            {
                if(in[i][j-1]==in[i][j])
                {
                    f=1;
                }
            }
            if(i<n-1)
            {
                if(in[i+1][j]==in[i][j])
                {
                    f=1;
                }
            }
            if(j<m-1)
            {
                if(in[i][j+1]==in[i][j])
                {
                    f=1;
                }
            }
            if(f)
            {
                final[i][j]=in[i][j];
                dist[i][j]=0;
                q.push(pair <ll,ll>(i, j));
            }
            else
            {
                final[i][j]=-1;
            }
        }
    }
    while(!q.empty())
    {
        pair <ll,ll> ele=q.front();
        q.pop();
        ll i=ele.fi;
        ll j=ele.se;
        if(i>0)
        {
            if(dist[i-1][j]==-1)
            {
                dist[i-1][j]=dist[i][j]+1;
                final[i-1][j]=final[i][j];
                q.push(pair<ll,ll>(i-1, j));
            } 
        }
        if(j>0)
        {
            if(dist[i][j-1]==-1)
            {
                dist[i][j-1]=dist[i][j]+1;
                final[i][j-1]=final[i][j];
                q.push(pair<ll,ll>(i, j-1));
            } 
        }
        if(i<n-1)
        {
            if(dist[i+1][j]==-1)
            {
                dist[i+1][j]=dist[i][j]+1;
                final[i+1][j]=final[i][j];
                q.push(pair<ll,ll>(i+1, j));
            } 
        }
        if(j<m-1)
        {
            if(dist[i][j+1]==-1)
            {
                dist[i][j+1]=dist[i][j]+1;
                final[i][j+1]=final[i][j];
                q.push(pair<ll,ll>(i, j+1));
            } 
        }
    }
    while(t--)
    {
        ll i, j;
        long long p;
        cin>>i>>j>>p;
        i--;
        j--;
        if((p>dist[i][j])&&(dist[i][j]!=-1))
        {
            cout<<(p+final[i][j])%2<<endl;
        }
        else
        {
            cout<<in[i][j]%2<<endl;
        }
        
    }
}