#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ceil (ll)ceil
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
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
//const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
#define MAXN (ll)1e7+4
ve <ll> spf(MAXN);
void sieve() 
{ 
    spf[1] = 1; 
    for (ll i=2; i<MAXN; i++) 
        spf[i] = i; 
  
    for (ll i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (ll i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (ll j=i*i; j<MAXN; j+=i) 
  
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
// A O(log n) function returning primefactorization after preprocessing the spf 
vector<ll> getFactorization(ll x) 
{ 
    vector<ll> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x];
    } 
    return ret; 
}
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
ll gcd(ll a,ll b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
int main()
{
    fastio
    ll n;
    cin>>n;
    ve <ll> a(n);
    inarr(i, a, n);
    sieve();
    ve <ll> a1(n, -1), a2(n, -1);
    fr(i, 0, n-1)
    {
        ve <ll> imp=getFactorization(a[i]);
        sort(all(imp));
        ve <pair <ll,ll>> util=compress_array(imp, sz(imp));
        if(sz(util)<=1)
        {
            a1[i]=-1;
            a2[i]=-1;
        }
        else
        {
            a1[i]=1;
            a2[i]=1;
            fr(j, 0, sz(util)-2)
            {
                a1[i]*=(util[j].fi);
            }
            a2[i]*=util[sz(util)-1].fi;
        }
    }
    outarr(i, a1, n);
    cout<<endl;
    outarr(i, a2, n);
    cout<<endl;
}