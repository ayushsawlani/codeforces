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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ve<ve <bool>> check(5005,ve <bool>(5005,true));
    ve<ve <ll>> dp(5005,ve <ll>(5005,0));
    ve<ve <ll>> ans(5005,ve <ll>(5005,0));
    fr(i, 0, sz(s)-1)
    {
        dp[i][i+1]=1;
        if(s[0]=='0')
            dp[i][i+1]=0;
    }
    fr(i, 0, sz(s)-1)
    {
        if(s[i]=='0')
        {
            fr(j, i, n-1)
            {
                check[i][j]=false;
            }
        }
    }
    fr(i, 0, sz(s)-1)
    {
        ve <ll> imp=z_array(s.substr(i, sz(s)-i));
        fr(l, 1, (sz(s)-i)/2)
        {
            ll j=i+l;
            ll k=j+imp[l];
            ll k_k=i+imp[l];
            if(k<j+l)
            {
                if(s[k]<s[k_k])
                {
                    check[j][j+l-1]=false;
                    //cout<<"x";
                    //cout<<k<<" "<<j<<" "<<j+l-1<<endl;
                }
            }
            else
            {
                check[j][j+l-1]=false;
                //cout<<"y";
                //cout<<k<<" "<<j<<" "<<j+l-1<<endl; 
            }
            
        }
    }
    fr(i, 0, sz(s)-1)
    {
//        cout<<i<<endl;
        fr(l, 1, i)
        {

            if(s[i-l+1]!='0')
            {
                dp[i][l]=ans[i-(l)][l-1];
                if(check[i-l+1][i])
                {
    //                cout<<"X"<<endl;
                    dp[i][l]+=dp[i-(l)][l];
                }
                dp[i][l]%=mod;
            }
  //          cout<<dp[i][l]<<endl;
            ans[i][l]=ans[i][l-1]+dp[i][l];
            ans[i][l]%=mod;
        }
//        cout<<endl;
        if(s[0]!='0')
            ans[i][i+1]=(ans[i][i]+1)%mod;
        fr(j, i+2, sz(s))
        {
            ans[i][j]=ans[i][j-1];   
        }
    }
    cout<<(ans[n-1][sz(s)])%mod<<endl;
}