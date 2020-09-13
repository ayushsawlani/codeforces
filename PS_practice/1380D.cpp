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
    ll n, m;
    cin>>n>>m;
    ll x, k, y;
    cin>>x>>k>>y;
    ve <ll> a(n), b(m);
    inarr(i, a, n);
    inarr(i, b, m);
    ll i=0;
    ll j=0;
    ve <bool> todel(n, true);
    while((i<n)&&(j<m))
    {
        if(a[i]==b[j])
        {
            //cout<<a[i]<<endl;
            todel[i]=false;
            j++;
        }
        i++;
    }
    if(j<m)
    {
        cout<<-1<<endl;
        return 0;
    }
   ll ans=0;
    i=0;
    while(i<n)
    {
        ll m1=-inf;
        ll m2=-inf; 
        if(i>0)
        {
            m1=a[i-1];
        }
        ll m3=-inf;
        ll c=0;
        while((todel[i])&&(i<n))
        {
            m3=max(m3, a[i++]);
            c++;
        }
        if(i<n)
        {
            m2=a[i];
        }
       // cout<<c<<endl;
        if(m3>max(m2, m1))
        {
            c-=k;
            ans+=x;
            if(c<0)
            {
                cout<<-1<<endl;
                return 0;
            }
            ans+=(c/k)*min(x, y*k)+y*(c%k);
        }
        else
        {
            ans+=(c/k)*min(x, y*k)+y*(c%k);
        }
        while((!todel[i])&&(i<n))
        {
            i++;
        }
    //    cout<<ans<<endl;
    }
    //ll ans=0;
    cout<<ans<<endl;
}