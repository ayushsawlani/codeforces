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
    fastio
    ll n, m;
    cin>>n>>m;
    ve <string> in(n);
    inarr(i, in, n);
    ll k;
    cin>>k;
    ve <pair <char, ll>> step(k);
    fr(i, 0, k-1)
    {
        cin>>step[i].fi>>step[i].se;
    }
    
    ve <ve <int>> left(n, ve<int>(m,-1));
    ve <ve <int>> up(n, ve<int>(m,-1));
    fr(i, 0, n-1)
    {
        fr(j, 0, m-1)
        {
            if(in[i][j]=='#')
            {
                left[i][j]=j;
            }
            else if(j>0)
            {
                left[i][j]=left[i][j-1];   
            }
            if(in[i][j]=='#')
            {
                up[i][j]=i;
            }
            else if(j>0)
            {
                up[i][j]=up[i-1][j];   
            }
        }
    }
    ve <char> ans;
    fr(i, 0, n-1)
    {
        fr(j, 0, m-1)
        {
            if((in[i][j]>='A')&&(in[i][j]<='Z'))
            {
                pair <int, int> cur(i, j);
                int flag=0;
                fr(l, 0, k-1)
                {
                    if(step[l].fi=='N')
                    {
                        if(up[cur.fi][cur.se]>=cur.fi-step[l].se)
                        {
                            flag=1;
                            break;
                        }
                        if(cur.fi-step[l].se<0)
                        {
                            flag=1;
                            break;
                        }
                        cur.fi-=step[l].se;
                    }
                    if(step[l].fi=='W')
                    {
                        if(left[cur.fi][cur.se]>=cur.se-step[l].se)
                        {
                            flag=1;
                            break;
                        }
                        if(cur.se-step[l].se<0)
                        {
                            flag=1;
                            break;
                        }
                        cur.se-=step[l].se;
                    }
                    if(step[l].fi=='E')
                    {
                        if(cur.se+step[l].se>=m)
                        {
                            flag=1;
                            break;
                        }
                        if(left[cur.fi][cur.se+step[l].se]>=cur.se)
                        {
                            flag=1;
                            break;
                        }
                        cur.se+=step[l].se;
                    }
                    if(step[l].fi=='S')
                    {
                        if(cur.fi+step[l].se>=n)
                        {
                            flag=1;
                            break;
                        }
                        if(up[cur.fi+step[l].se][cur.se]>=cur.fi)
                        {
                            flag=1;
                            break;
                        }
                        cur.fi+=step[l].se;
                    }
                }
                if(flag==0)
                {
                    ans.pb(in[i][j]);
                }
            } 
        }
    }
    if(sz(ans)==0)
    {
        cout<<"no solution"<<endl;
    }
    else
    {
        sort(ans.begin(), ans.end());
        fr(i, 0, sz(ans)-1)
        {
            cout<<ans[i];
        }
        cout<<endl;
    }
    //*/
}