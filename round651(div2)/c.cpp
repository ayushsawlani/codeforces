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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n==1)
        {
            cout<<"FastestFinger"<<endl;
            continue;
        }
        if(n==2)
        {
            cout<<"Ashishgup"<<endl;
            continue;
        }
        if(n%2)
        {
            cout<<"Ashishgup"<<endl;
            continue;
        }
        ve <ll> fac;
        fr(i, 1, sqrt(n))
        {
            if(n%i==0)
            {
                fac.pb(i);
                if(i!=n/i)
                    fac.pb(n/i);
            }
        }
        string ans="FastestFinger";
        ll f=0;
        ll m1=1;
        fr(i, 0, sz(fac)-1)
        {
            if(fac[i]%2)
            {
                m1=max(m1, fac[i]);
            }
        }
        if(m1!=1)
        {
            n=n/m1;
            if(n>2)
            {
                ans="Ashishgup";
            }
            else
            {
                fr(i, 2, sqrt(m1))
                {
                    if(m1%i==0)
                        ans="Ashishgup";
                }
            }
        }
        cout<<ans<<endl;
    }
}