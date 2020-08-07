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
//#define ll long long int
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
//const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
void dfs(ve <ve <pair <ll,ll>>>&in, ve <ve <ll>> &c, ve <ve <pair <ll,ll>>> &pi, ve <ve <char>> &ans, pair <ll,ll> seed, ll n)
{
    ll row=seed.fi;
    ll col=seed.se;
    c[row][col]=1;
    if(in[row][col]==seed)
    {
        ans[row][col]='X';
    }
    if(row>0)
    {
        if((c[row-1][col]==0)&&(in[row][col]==in[row-1][col]))
        {
            ans[row-1][col]='D';
            dfs(in, c, pi, ans, mk(row-1, col), n);
        }
    }
    if(col>0)
    {
        if((c[row][col-1]==0)&&(in[row][col]==in[row][col-1]))
        {
            ans[row][col-1]='R';
            dfs(in, c, pi, ans, mk(row, col-1), n);
        }
    }
    if(col<n-1)
    {
        if((c[row][col+1]==0)&&(in[row][col]==in[row][col+1]))
        {
            ans[row][col+1]='L';
            dfs(in, c, pi, ans, mk(row, col+1), n);
        }
    }
    if(row<n-1)
    {
        if((c[row+1][col]==0)&&(in[row][col]==in[row+1][col]))
        {
            ans[row+1][col]='U';
            dfs(in, c, pi, ans, mk(row+1, col), n);
        }
    }
}
int main()
{
    fastio
    ll n;
    cin>>n;
    ve <ve <char>> ans(n,ve <char>(n,'0'));
    ve <ve <pair<ll,ll>>>in(n, ve <pair <ll,ll>>(n)), pi(n, ve <pair <ll,ll>>(n));
    ve <ve <ll>> c(n, ve <ll> (n, 0));
    fr(i, 0, n-1)
    {
        fr(j, 0, n-1)
        {
            cin>>in[i][j].fi>>in[i][j].se;
            in[i][j].fi--;
            in[i][j].se--;
        }
    }
    fr(i, 0, n-1)
    {
        fr(j, 0, n-1)
        {
            if((c[i][j]==0)&&(in[i][j]==mk(i, j)))
            {
                dfs(in, c, pi, ans, mk(i, j), n);
            }
        }
    }
    fr(i, 0, n-1)
    {
        fr(j, 0, n-1)
        {
            if(in[i][j].fi<0)
            {
                ll f=0;
                if(i>0)
                {
                    if(in[i-1][j].fi<0)
                    {
                        ans[i][j]='U';
                        ans[i-1][j]='D';
                        f=1;
                    }
                }
                if(j>0)
                {
                    if(in[i][j-1].fi<0)
                    {
                        ans[i][j]='L';
                        ans[i][j-1]='R';
                        f=1;
                    }
                }
            }
        }
    }
    fr(i, 0, n-1)
    {
        fr(j, 0, n-1)
        {
            if(ans[i][j]=='0')
            {
                cout<<"INVALID"<<endl;
                return 0;
            }
        }
    }
    cout<<"VALID"<<endl;
    fr(i, 0, n-1)
    {
        fr(j, 0, n-1)
        {
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    //*/
}