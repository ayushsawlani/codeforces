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
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
ll func(ll n)
{
    return((n)*(n+1))/2;
}
int main()
{
    //fastio
    ll n, x;
    cin>>n>>x;
    ve <ll> in(2*n);
    inarr(i, in, n);
    fr(i, n, 2*n-1)
    {
        in[i]=in[i-n];
    }
    ve <ll> pre(2*n, 0);
    ve <ll> dpre(2*n, 0);
    pre[0]=func(in[0]);
    dpre[0]=in[0];
    fr(i, 1, 2*n-1)
    {
        pre[i]=pre[i-1]+func(in[i]);
        dpre[i]=dpre[i-1]+in[i];
    }
    ll i=n;
    ll j=0;
    ll ans=-1;
    while(i!=2*n)
    {
        if(dpre[i]-dpre[j]>=x)
        {
            j++;
        }
        else
        {
            //cout<<i<<" "<<j<<endl;
            ans=max(ans, pre[i]-pre[j]+func(in[j<n?j:j-n])-func(in[(j<n?j:j-n)]-(x-dpre[i]+dpre[j]))); 
            //cout<<ans<<" "<<pre[i]-pre[j]+func(in[(j<n?j:j-n)])-func(in[(j<n?j:j-n)]-(x-pre[i]+pre[j]))<<endl;     
            i++;
        }
    }
    cout<<ans<<endl;
}