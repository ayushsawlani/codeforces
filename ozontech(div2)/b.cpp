#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ceil (ll)ceil
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
    string s;
    cin>>s;
    ll n=sz(s);
    ve <ll> con;
    fr(i, 0, n-1)
    {
        if(s[i]=='(')
        {
            con.pb(0);
        }
        else
        {
            con.pb(1);
        }
    }
    ve <ll> col(n, 1);
    ve <ve <ll>> ans;
    while(1)
    {
        ve <ll> suff(n, 0);
        frn(i, n-1, 0)
        {
            if(i<n-1)
            {
                suff[i]=suff[i+1];
            }
            if((col[i]==1)&&(con[i]==1))
            {
                suff[i]++;
            }
        }
        ll c1=0;
        ll j=-1;
        ll del=0;
        fr(i, 0, n-2)
        {
            if((col[i])&&(con[i]==0))
            {
                c1++;
            }
            if(min(c1, suff[i+1])>del)
            {
                j=i;
                del=min(c1, suff[i+1]);
            }
        }
        if(del==0)
            break;
        ans.pb(ve <ll>());        
        c1=0;
        fr(i, 0, j)
        {
            if(c1==del)
                break;
            if((col[i])&&(con[i]==0))
            {
                col[i]=0;
                ans[sz(ans)-1].pb(i+1);       
                c1++;
            }
        }
        c1=0;
        frn(i, n-1, j+1)
        {
            if(c1==del)
                break;
            if((col[i])&&(con[i]))
            {
                col[i]=0;
                ans[sz(ans)-1].pb(i+1);       
                c1++;
            }
        }
        sort(all(ans[sz(ans)-1]));
    }
    cout<<sz(ans)<<endl;
    for(auto j:ans)
    {
        cout<<sz(j)<<endl;
        for(auto jj:j)
        {
            cout<<jj<<" ";
        }
        cout<<endl;
    }
}