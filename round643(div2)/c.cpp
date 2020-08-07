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
#define fr(i, a, b) for (ll i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
int main()
{
    //fastio
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ve <ll> num(b+c+3, 0);
    ll ans=0;
    fr(i, max(a+b,c+1), b+c)
    {
        num[i]=i+1-max((i-b),(ll)0)-max((i-c),(ll)0);
        num[i]-=max(min(b-1, i-a)-max(i-b, (ll)0)+1,(ll)0);
        num[i]-=max(min(a-1, i-b)-max(i-c, (ll)0)+1,(ll)0);
        if(i>d)
        {
            ans=ans+num[i]*(d-c+1);
        }
        else if(i>c)
        {
            ans=ans+num[i]*(i-c);
        }
    }
    cout<<ans<<endl;
}
