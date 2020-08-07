#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define pb push_back
//#define mod 1000000007
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
ve <ll> fac(2e5+5), twos(2e5+5);
vector <pair <ll,ll>> compress_array(vector <ll> a, ll n)
{
    vector <pair <ll,ll>> ans;
    ll i=0;
    ll c=1;
    while(i<n-1)
    {
        if(a[i]!=a[i+1])
        {
            pair <ll,ll> temp;
            temp.first=a[i];
            temp.second=c;
            ans.push_back(temp);
            c=1;
        }
        else
        {
            c++;
        }
        i++;   
    }
    pair <ll,ll> temp;
    temp.first=a[i];
    temp.second=c;
    ans.push_back(temp);
    c=1;
    return ans;
}
long long int fast_expo(ll a, ll n,ll mod)
{
	ll ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=((ans*a)%mod);
		a=((a*a)%mod);
		n=n/2;
	}
	return ans;
}
ll gettwos(ll x)
{
    ll ans=0;
    while((x%2==0)&&(x>0))
    {
        ans++;
        x=x/2;
    }
    return ans;
}
int main()
{
    //fastio
    fac[0]=1;
    twos[0]=0;
    ll n;
    cin>>n;
    ve <pair <ll,ll>> in1;
    fr(i, 0, n-1)
    {
        ll x;
        cin>>x;
        in1.pb(pair <ll,ll>(x,i));
    }
    fr(i, 0, n-1)
    {
        ll x;
        cin>>x;
        in1.pb(pair <ll,ll>(x,i));
    }
    ll mod;
    cin>>mod;
    fr(i, 1, 2e5+4)
    {
        twos[i]=gettwos(i)+twos[i-1];
        ll _t=i/pow(2, gettwos(i));
        fac[i]=fac[i-1]*_t;
        fac[i]%=mod;
    }
    
    sort(in1.begin(), in1.end());
    ve <ll> util;
    util.pb(in1[0].se);
    ll ans=1;
    ll twosum=0;
    fr(i, 0, 2*n-2)
    {
        if(in1[i].fi==in1[i+1].fi)
        {
            util.pb(in1[i+1].se);
        }
        else
        {
            ans*=fac[sz(util)];
            ans%=mod;
            twosum+=twos[sz(util)];
            ve <pair <ll,ll>> util2=compress_array(util, sz(util));
            fr(j, 0, sz(util2)-1)
            {
                if(util2[j].se==2)
                    twosum--;
            }
            util.clear();
            util.pb(in1[i+1].se);
        }
    }
    ans*=fac[sz(util)];
    ans%=mod;
    twosum+=twos[sz(util)];
    ve <pair <ll,ll>> util2=compress_array(util, sz(util));
    fr(j, 0, sz(util2)-1)
    {
        if(util2[j].se==2)
            twosum--;
    }   
    ans*=fast_expo(2, twosum, mod);
    ans%=mod;
    cout<<ans<<endl;
//*/
}