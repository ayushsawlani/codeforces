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
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
ve <ll> z_array(string s)
{
    ve <ll> ans(sz(s));
    ans[0]=-1;
    ll l=0,r=0;
    for(ll i=1;i<s.size();i++)
    {
        if(i>r)
        {
            l=i;
            r=i;
            while((r<s.size())&&(s[r]==s[r-i]))
            {
                r++;
            }
            r--;
            ans[i]=r-l+1;
        }
        else
        {
            ll k=i-l;
            if(ans[k]+i<=r)
            {
                ans[i]=ans[k];
            }
            else
            {
                l=i;
                while((r<s.size())&&(s[r]==s[r-i]))
                {
                    r++;
                }
                r--;
                ans[i]=r-l+1;
            }
            
        }
    }
    return ans;
}
int main()
{
    //fastio
    string s, t;
    cin>>s>>t;
    ll tsize=sz(t);
    ll ssize=sz(s);
    string util=t+s;
    ve <ll> match=z_array(util);
    ll n=sz(match);
    ve <ll> dp1(n,0),dp2(n,0),sum(n,0);
    fr(i, 2*tsize-1, sz(match))
    {
        if(match[i-tsize+1]<tsize)
        {
            dp1[i]=dp1[i-1];
        }
        else
        {
            dp1[i]=sum[i-tsize]+i-tsize+1-(tsize)+1;
        }
        dp2[i]=dp1[i-1]+dp2[i-1];
        sum[i]=sum[i-1]+dp1[i]+dp2[i];
        dp1[i]%=mod;
        dp2[i]%=mod;
        sum[i]%=mod;
    }
    cout<<(dp1[sz(match)-1]+dp2[sz(match)-1])%mod<<endl;
}