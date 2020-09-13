#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define pb push_back
#define mod 1000000007
#define inarr(i,arr,n); for(ll i=0;i<n;i++) scanf("%d",&arr[i]);
#define outarr(i,arr,n); for(ll i=0;i<n;i++) printf("%d ",arr[i]);
#define swap(a,b,t) {t=a;a=b;b=t;}
#define ve vector
#define sz(a) (int)((a).size())
#define fi first
#define se second
#define pa pair
#define fastio  {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define ll int
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
//const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
ll gcd(ll a,ll b)
{
	if(a==-1)
		return b;
	else if(b==-1)
		return a;
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
ll stk(ll n)
{
    ll k=1;
    for(;k<n;k=k*2);
    return k;
}
vector <ll> buildst(vector <ll> a,ll n)
{
    ll k=stk(n);
    vector <ll> ans(2*k-1);
    for(ll i=0;i<2*k-1;i++)
        ans[i]=-1;
    for(ll i=k-2+n;i>=k-1;i--)
        ans[i]=a[i-k+1];
    return ans;
}

ll getgcd(ve <ll> &gcdtree, ll i, ll j, ll l, ll r,ll k)
{
	if((j<l)||(r<i))
		return -1;
	else if((i>=l)&&(j<=r))
		return gcdtree[k];
	else
	{
		ll m=(i+j)/2;
		return gcd(getgcd(gcdtree, i, m, l, r, 2*k+1  ),getgcd(gcdtree, m+1, j, l, r, 2*k+2  ));
	}
}
ll bin1(ll x,ll l, ll r, ve <ll> &gcdtree,ll n){
    ll i=l;//starting range
    ll j=r;//ending range
    while(i<j)//not i==j , i==j pe break because range me single element
    {
        ll mid=(i+j)/2;
        if(getgcd(gcdtree, 0, n-1, mid, r, 0)>x)
            j=mid-1;
        else if(getgcd(gcdtree, 0, n-1, mid, r, 0)<x)
        {
            i=mid+1;
        }
		else
		{
			j=mid;
		}
    }
	//element does not exist
    return i;
}
ll bin2(ll x,ll l, ll r, ve <ll> &gcdtree,ll n){
    ll i=l;//starting range
    ll j=r;//ending range
    while(i<j)//not i==j , i==j pe break because range me single element
    {
        ll mid=(i+j+1)/2;
        if(getgcd(gcdtree, 0, n-1, l, mid, 0)>x)
            i=mid+1;
        else if(getgcd(gcdtree, 0, n-1, l, mid, 0)<x)
        {
            j=mid-1;   
        }
		else
		{
			i=mid;
		}
    }

    return i;
}
// doesn't pass, use sparse table
int main()
{
    fastio
	ll n;
	scanf("%d", &n);
	ve <ll> in(n);
	inarr(i, in, n);
	ve <ll> gcdtree=buildst(in,n);
	frn(i,stk(n)-2,-1)
	{
		gcdtree[i]=gcd(gcdtree[2*i+1],gcdtree[2*i+2]);
	}
	ll ans=0;
	fr(i, 0, n)
	{
		ll l=min((ll)i, bin1(in[i], 0, i, gcdtree,stk(n)));
		ll r=max((ll)i, bin2(in[i], i, n-1, gcdtree,stk(n)));
		ans=max(ans, r-l);
	}
	ve <ll> util;
	ll c=0;
	fr(i, 0, n)
	{
		ll l=min((ll)i, bin1(in[i], 0, i, gcdtree,stk(n)));
		ll r=max((ll)i, bin2(in[i], i, n-1, gcdtree,stk(n)));
		if(r-l==ans)
		{
			util.pb(l+1);
		}
	}
	ve <ll> util1;
	fr(i,0,sz(util)-1)
		if(util[i]!=util[i+1])
			util1.pb(util[i]);
	util1.pb(util[sz(util)-1]);
	printf("%d %d\n",sz(util1),ans);
	outarr(i, util1, sz(util1));
	cout<<endl;	
}