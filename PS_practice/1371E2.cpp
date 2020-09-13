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
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
int main()
{
    //fastio
    ll n, p;
    cin>>n>>p;
    ve <ll> in(n);
    inarr(i, in, n);
    sort(all(in));
    ve <ll> imp;
    ll diff=1;
    fr(i, 0, n-1)
    {
        diff=min(diff, i-in[i]);
    }
    ll x=(-diff);
    //cout<<x<<endl;
    ll pt1=0, pt2=0; 
    while((pt2<n)&&(pt1<n))
    {
        if(x+pt2>=in[pt1])
        {
            pt1++;
        }
        else
        {
            imp.pb(pt1-pt2);
            pt2++;
        }
        
    }
    while(pt2<n)
    {
        imp.pb(pt1-pt2);
        pt2++;
    }
    //outarr(i, imp, n);
    ve <ll> rightmost(p, -1);
    fr(i, 0, n-1)
    {
        rightmost[imp[i]%p]=max(rightmost[imp[i]%p], (ll)i);  
    }
    ve <ll> ans;
    fr(i, 0, p-1)
    {
        if(rightmost[(p-i)%p]<i)
            ans.pb(x+i);
    }
    cout<<sz(ans)<<endl;
    outarr(i, ans, sz(ans));
    cout<<endl;
}