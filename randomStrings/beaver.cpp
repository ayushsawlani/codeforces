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
    string s;
    cin>>s;
    ll n;
    cin>>n;
    ve< string> bor(n);
    inarr(i, bor, n);
    set <pair <ll,ll>> bad;
    ve <ll> start(sz(s), -1);
    fr(i, 0, n-1)
    {
        string util=bor[i]+"*"+s;
        ve <ll> zimp=z_array(util);
        fr(j, sz(bor[i])+1, sz(util)-1)
        {
            if(zimp[j]==sz(bor[i]))
            {
                start[j-2]=max(start[j-2], (ll)j-sz(bor[i])-1);
            }
        }
    }
    ve <ll> dp(sz(s)+5,0);
    ll ans1, ans2;
    dp[0]=1;
    if(start[0]!=-1)
    {
        dp[0]=0;
    }
    ans1=0;
    ans2=dp[0];
    fr(i, 1, sz(s)-1)
    {
        if(start[i]==-1)
        {
            dp[i]=dp[i-1]+1;
        }
        else
        {
            if(i-start[i]+1>dp[i-1]+1)
            {
                dp[i]=dp[i-1]+1;
            } 
            else
            {
                dp[i]=i-start[i];
            }
            
        }
        if(ans2<dp[i])
        {
            ans2=dp[i];
            ans1=i-dp[i]+1;
        }
    }
    cout<<ans2<<" "<<ans1<<endl;
}