#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
int main()
{
 
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ve<ll> p(n),c(n);
        fr(i, 0, n)
            cin>>p[i]>>c[i];
        string ans="YES";
        fr(i,0,n-1)
        {
            if(p[i]>p[i+1])
                ans="NO";
            if(c[i]>c[i+1])
                ans="NO";
            if(p[i+1]-p[i]<c[i+1]-c[i])
                ans="NO";
        }
        fr(i,0,n)
        {
            if(c[i]>p[i])
                ans="NO";
        }
        cout<<ans<<endl;
    }
}