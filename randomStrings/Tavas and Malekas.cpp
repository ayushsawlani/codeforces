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
ll fast_expo(ll a, ll n)
{
	int ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		n=n/2;
	}
	return ans;
}
int main()
{
    //fastio
    ll n, m;
    cin>>n>>m;
    string p;
    cin>>p;
    ve <ll> pos(m);
    inarr(i, pos, m);
    ve <ll> util=z_array(p);
    ve <char> s(n);
    set <ll> check;
    fr(i, 0, sz(util)-1)
    {
        if(i+util[i]==sz(util))
        {
            check.insert(i+1);
        }  
    }
    check.insert(0);
    sort(pos.begin(), pos.end());
    if(m==0)
    {
        cout<<fast_expo(26, n)<<endl;
        return 0;
    }
    ll ans=fast_expo(26,pos[0]-1);
    fr(i, 0, m-2)
    {
        if(pos[i+1]-pos[i]>=sz(p))
        {
            ans*=fast_expo(26,(pos[i+1]-pos[i]-sz(p)));
            ans%=mod;
        }
        else
        {
            if(check.find(pos[i+1]-pos[i]+1)==check.end())
            {
                ans=0;
                break;
            }
        }
    }
    ans*=fast_expo(26, n-1-(pos[m-1]-1)+1-sz(p));
    ans%=mod;
    cout<<ans<<endl;
}