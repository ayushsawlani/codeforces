#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
//cout << fixed << setprecision(9) << ans <<endxl; for accurate decimal precision.
int main()
{
    fastio
    string s;
    cin>>s;
    ve <ve <ll>> check(sz(s), ve<ll> (sz(s), 0));
    ve <ve <ll>> ans(sz(s), ve<ll> (sz(s), 0));
    fr(i, 0, sz(s)-1)
    {
        check[i][i]=1;
        ans[i][i]=1;
    }
    fr(l, 2, sz(s))
    {
        fr(i, 0, sz(s)-l)
        {
            ll j=i+l-1;
            if(s[i]==s[j])
                if((check[i+1][j-1])||(i+1==j))
                {
                    check[i][j]=1;
                }
        }
    }
    /*fr(i, 0, sz(s)-1)
    {
        fr(j, i, sz(s)-1)
        {
            cout<<i<<" "<<j<<" "<<check[i][j]<<endxl;
        }
        cout<<endxl;
    }
    //*/
   fr(l, 2, sz(s))
    {
        fr(i, 0, sz(s)-l)
        {
            ll j=i+l-1;
            ans[i][j]=ans[i][j-1]+ans[i+1][j]-ans[i+1][j-1];
            if(check[i][j])
                ans[i][j]++;
        }
    }
    ll q;
    cin>>q;
    while(q--)
    {
        ll l,r; cin>>l>>r;
        cout<<ans[l-1][r-1]<<endxl;
    }
}