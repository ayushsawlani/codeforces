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
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, m;
        cin>>n>>m;
        ve <string> in(n);
        ve <ve <ll>> col(n, ve <ll> (m, 0));
        inarr(i, in, n);
        fr(i, 0, n-1)
        {
            fr(j, 0, m-1)
            {
                if(in[i][j]=='B')
                {
                    if(i>0)
                    {
                        if(in[i-1][j]=='.')
                        {
                            in[i-1][j]='#';
                        }
                    }
                    if(j>0)
                    {
                        if(in[i][j-1]=='.')
                        {
                            in[i][j-1]='#';
                        }
                    }
                    if(i<n-1)
                    {
                        if(in[i+1][j]=='.')
                        {
                            in[i+1][j]='#';
                        }
                    }
                    if(j<m-1)
                    {
                        if(in[i][j+1]=='.')
                        {
                            in[i][j+1]='#';
                        }
                        
                    }
                }
            }
        }
        ve <pair <ll,ll>> pr;
        if(in[n-1][m-1]!='#')
            pr.pb(mk(n-1, m-1));
        while(!(pr.empty()))
        {
            pair <ll,ll> vis=pr[sz(pr)-1];
            pr.pop_back();
            ll i=vis.fi;
            ll j=vis.se;
            col[i][j]=1;
            if(i>0)
            {
                if((in[i-1][j]!='#')&&(col[i-1][j]==0))
                {
                    pr.pb(mk(i-1, j));
                }
            }
            if(j>0)
            {
                if((in[i][j-1]!='#')&&(col[i][j-1]==0))
                {
                    pr.pb(mk(i,j-1));
                }
            }
            if(i<n-1)
            {
                if((in[i+1][j]!='#')&&(col[i+1][j]==0))
                {
                    pr.pb(mk(i+1, j));
                }
            }
            if(j<m-1)
            {
                if((in[i][j+1]!='#')&&(col[i][j+1]==0))
                {
                    pr.pb(mk(i, j+1));
                }
            }
        }
        string ans="Yes";
        fr(i, 0, n-1)
        {
            fr(j, 0, m-1)
            {
                if(in[i][j]=='G')
                {
                    if(col[i][j]==0)
                    {
                        ans="No";
                    }
                }
                if(in[i][j]=='B')
                {
                    if(col[i][j])
                    {
                        ans="No";
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}