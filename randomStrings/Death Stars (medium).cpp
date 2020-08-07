#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define pb push_back
#define mod 1299827
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
ll fast_expo(ll a, ll n)
{
	ll ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		n=n/2;
	}
	return ans;
}
ll hashcompute(string &s)
{
    ll ans=0;
    ll x=1;
    frn(i, sz(s)-1, 0)
    {
        ans+=((s[i]-'a')*x);
        x=x*26;
        x%=mod;
        ans%=mod;
    }
    return ans;
}
ll hashcomputex(string &s,ll m)
{
    ll ans=0;
    ll x=1;
    frn(i, sz(s)-1, 0)
    {
        ans+=((s[i]-'a')*x);
        x=x*fast_expo(26,m);
        x%=mod;
        ans%=mod;
    }
    return ans;
}
bool check(ve <string> &grid1,ll i1,ll j1, ve <string> &grid2,  ll i2,ll j2)
{
    ll m=j1-i1+1;
    ve <string> mat1(j1-i1+1);
    ve <string> mat2(j1-i1+1);
    fr(i, i1, j1)
    {
        fr(j, 0, m-1)
        {
            mat1[i-i1].pb(grid1[i][j]);
        }
    }
    fr(i, 0, m-1)
    {
        fr(j, i2, j2)
        {
            mat2[i].pb(grid2[i][j]);
        }
    }
    if(mat2==mat1)
        return true;
    return false;
}
int main()
{
    //fastio
    ll n, m; cin>>n>>m;
    ve <ve <pair <ll,ll>>> hashtable(mod, ve <pair <ll,ll>>());
    ve <string> grid1(n);
    fr(i, 0, n-1)
    {
        cin>>grid1[i];
    }
    ll val=0;
    fr(i, 0, m-1)
    {
        val=val*fast_expo(26, m);
        val%=mod;
        val+=hashcompute(grid1[i]);
        val%=mod;
    }
    hashtable[val].pb(pair <ll,ll>(0, m-1));
    fr(j, m, n-1)
    {
        val=val-((hashcompute(grid1[j-m])*fast_expo(26, m*(m-1)))%mod);
        val+=mod;
        val%=mod;
        val*=fast_expo(26, m);
        val%=mod;
        val+=hashcompute(grid1[j]);
        val%=mod;
        hashtable[val].pb(pair <ll,ll>(j-m+1,j));
    }
    //cout<<val<<endl;
    ve <string> grid2(m);
    inarr(i, grid2, m);
    val =0;
    fr(i, 0, m-1)
    {
        val=(val*26)%mod;
        string s;
        fr(j, 0, m-1)
        {
            s.pb(grid2[j][i]);
        }
        val=val+hashcomputex(s, m);
        val%=mod;
    }
    if(sz(hashtable[val]))
    {
        for(auto it:hashtable[val])
        {
            if(check(grid1, it.fi, it.se, grid2, 0, m-1))
            {
                cout<<it.fi+1<<" "<<1<<endl;
                return 0;
            }
        }
    }
    fr(j, m, n-1)
    {
        string s1="", s2="";
        fr(i, 0, m-1)
        {
            s2.pb(grid2[i][j]);
            s1.pb(grid2[i][j-m]);
        }
        val=val-((hashcomputex(s1, m)*fast_expo(26, m-1))%mod);
        val+=mod;
        val%=mod;
        val*=26;
        val%=mod;
        val+=hashcomputex(s2, m);
        val%=mod;
        s1.clear();
        s2.clear();
        if(sz(hashtable[val]))
        {
            for(auto it:hashtable[val])
            {
                if(check(grid1, it.fi, it.se, grid2, j-m+1, j))
                {
                    cout<<it.fi+1<<" "<<j-m+1+1<<endl;
                    return 0;
                }
            }
        }
        //*/
    }
    //*/
}