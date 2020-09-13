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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ve <ll> in(n);
        inarr(i, in, n);
        ve <ll> count(n, 0);
        fr(i, 1, n-1)
        {
            count[i]=count[i-1];
            if((in[i-1]<in[i])&&(in[i]>in[i+1]))
            {
                count[i]++;
            }
        }
        ll i=1;
        ll j=1+k-3;
        ll ans=0;
        ll al=2;
        while(j<n-1)
        {
            if(ans<count[j]-count[i-1]+1)
                al=i-1+1;
            ans=max(count[j]-count[i-1]+1,ans);
            i++;
            j++;
        }
        cout<<ans<<" "<<al<<endl;
    }
}