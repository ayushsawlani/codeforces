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
    ll t; cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ve <ll> a(n);
        inarr(i, a, n);
        map <ll,ll> m;
        string ans="YES";
        fr(i, 0, n)
        {
            ll c=0;
            while(a[i]>0)
            {
                if(m.find(c)==m.end())
                {
                    m[c]=a[i]%k;
                }
                else
                {
                    m[c]+=(a[i]%k);
                }
                if(m[c]>1)
                    ans="NO";
                a[i]=a[i]/k;
                c++;
            }
        } 
        cout<<ans<<endl;
    }
}