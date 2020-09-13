#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ceil (ll)ceil
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
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 2e9+5;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
ll sum(ll n)
{
    return (n*(n+1))/2;
}
ll func(ll n, ll x, ll y, ll d)
{
    ll ans=(d+1)*(d+2)*2;
    ans-=(4*(d+1));
    ans+=1;
    ans-=(d+x>n?sum(d+x-n)+sum(d+x-n-1):0);
    ans-=(d+y>n?sum(d+y-n)+sum(d+y-n-1):0);
    ans-=(x-d<=0?sum(1-x+d)+sum(d-x):0);
    ans-=(y-d<=0?sum(1-y+d)+sum(d-y):0);
    ans+=(x+(n+1)-y-d<=0?sum(1-(x+(n+1)-y-d)):0);
    ans+=(y+(n+1)-x-d<=0?sum(1-(y+(n+1)-x-d)):0);
    ans+=(x+y-d<=0?sum(1-(x+y-d)):0);
    ans+=(x+y-(n+1)+d>=n?sum(x+y-(n+1)+d-n):0);
    return ans;
}
int main()
{
    //fastio
    ll n, x, y, c;
    cin>>n>>x>>y>>c;
    //ll tr;
    //cin>>tr;
    ll i=0;
    ll j=inf;
    //cout<<func(n, x, y, tr);
    ///*
    while(i<j)
    {
        ll mid=(i+j)/2;
        ll utl=func(n, x, y, mid);
        if(utl>=c)
        {
            j=mid;
        }
        else
        {
            i=mid+1;
        }
    }
    cout<<j<<endl;
    //*/
}