#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define pb push_back
#define mod 1000000007
#define hashmod 1299827
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
bool check(string &s, ll i1, ll i2,ll l)
{
    fr(i, 0, l-1)
    {
        if(s[i+i1]!=s[i+i2])
            return false;
    }
    return true;
}
ll fast_expo(ll a, ll n)
{
	int ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=(ans*a)%hashmod;
		a=(a*a)%hashmod;
		n=n/2;
	}
	return ans;
}
ve <ll> lpsarray(string pat)
{
    ll M=sz(pat);
    ve <ll> lps(sz(pat), 0);
    int len = 0;   
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    }
    return lps;
}
int main()
{
    //fastio
    string s, pre, suf;
    cin>>s>>pre>>suf;
    ve <ll> prez=z_array(pre+"*"+s);
    ve <ll> sufz=z_array(suf+"*"+s);
    ll ans=0;
    ve <ve <bool>> check(sz(s), ve <bool> (sz(s), true)); 
    fr(i, 0, sz(s)-1)
    {
        ve <ll> util=lpsarray(s.substr(i, sz(s)-i));
        fr(j, i+max(sz(pre), sz(suf))-1, sz(s)-1)
        {
            if(check[i][j])
            {

                if((prez[i+sz(pre)+1]==sz(pre))&&(sufz[j+2]==sz(suf)))
                {
                    ans++;
                }
            }
        }
        
        fr(j, i+1, sz(s)-1)
        {
            if(util[j-i])
            {
                check[j-util[j-i]+1][j]=false;
            }
        }
        //*/
    }
    cout<<ans<<endl;
}