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
//const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
void get_check(string s, ve <ve <bool>> &check)
{
    fr(i, 0, sz(s)-1)
    {
        check[i][i]=1;
    }
    fr(l, 2, sz(s))
    {
        fr(i, 0, sz(s)-l)
        {
            ll j=i+l-1;
            if(s[i]==s[j])
                if((check[i+1][j-1])||(i+1==j))
                {
                    check[i][j]=true;
                }
        }
    }
}
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
    fastio
    string s;
    cin>>s;
    ve <ve <ll>>rep(sz(s), ve <ll> (sz(s), 0));
    fr(i, 0, sz(s)-1)
    {
        string imps=s.substr(i, sz(s)-i)+"*"+s;
        ve <ll> imparr=z_array(imps);
        fr(j, i, sz(s)-1)
        {
            rep[i][j]=imparr[j+sz(s)-i+1];
        }
    }
    ve <ve <ll>> order(sz(s), ve <ll> (sz(s),0));
    ve <ll> ans(sz(s),0);
    fr(i, 0, sz(s)-1)
    {
        order[i][i]=1;
        ans[0]++;
    }
    fr(l, 2, sz(s))
    {
        fr(i, 0, sz(s)-l)
        {
            ll j=i+l-1;
            if(s[i]==s[j])
            {
                if(order[i+1][j-1])
                {
                    ll mid=(i+j+2)/2;
                    if(rep[i][mid]>=l/2)
                        order[i][j]=order[mid][j]+1;
                    else
                    {
                        order[i][j]=1;
                    }
                    ans[order[i][j]-1]++;
                }
                if(i+1==j)
                {
                    order[i][j]=2;
                    ans[order[i][j]-1]++;
                }
            }
        }
    }
    frn(i, sz(s)-2, 0)
    {
        ans[i]=ans[i+1]+ans[i];
    }
    outarr(i, ans, sz(s));
    cout<<endl;
}