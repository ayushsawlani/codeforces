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
const ll inf = 1e18;
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve<ld> in(n);
    inarr(i,in,n);
    sort(in.begin(), in.end());
    if(in[sz(in)-1]==1)
    {
        cout<<1<<endl;
        return 0;
    }
    ld s=0, p=1;
    ld ans=-1;
    frn(i,n-1,-1)
    {
        s+=((in[i])/(1-in[i]));
        p*=(1-in[i]);
        ans=max(ans, s*p);   
    }
    cout << fixed << setprecision(9) << ans <<endl; 
}