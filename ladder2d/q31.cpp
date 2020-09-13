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
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
int main()
{
    //fastio
    ll n,m;
    cin>>n>>m;
    ve<ll> mark1(n,0), mark2(n,0);
    fr(i, 0, m)
    {
        ll x,y;
        cin>>x>>y;
        mark1[x-1]=1;
        mark2[y-1]=1;
    }
    ll ans=0;
    fr(i,1,n-1)
    {
        if(mark1[i]==0)
            ans++;
        if(mark2[i]==0)
            ans++;
    }
    if(n%2==1){
        if((mark1[(n+1)/2-1]==0)&&(mark2[(n+1)/2-1]==0))
            ans--;
    }
    cout<<ans<<endl;
    
}