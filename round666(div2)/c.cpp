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
    t=1;
    while(t--)
    {
        ll n;
        cin>>n;
        ve <ll> in(n);
        inarr(i, in, n);
        if(n==1)
        {
            cout<<1<<" "<<1<<endl;
            cout<<0<<endl;
            cout<<1<<" "<<1<<endl;
            cout<<0<<endl;
            cout<<1<<" "<<1<<endl;
            cout<<-in[0]<<endl;
            continue;
        }
        ve <ve <ll>> ans(3);
        fr(i, 0, n-2)
        {
            ans[0].pb((in[i]%n)*(n-1));
            in[i]+=((in[i]%n)*(n-1));
        }
        ans[1].pb(-(in[n-1]%n));
        in[n-1]+=(-(in[n-1]%n));
        fr(i, 0, n-1)
        {
            ans[2].pb(-in[i]);
            in[i]-=in[i];
        }
        cout<<1<<" "<<n-1<<endl;
        outarr(i, ans[0], n-1);
        cout<<endl;
        cout<<n<<" "<<n<<endl;
        outarr(i, ans[1], 1);
        cout<<endl;
        cout<<1<<" "<<n<<endl;
        outarr(i, ans[2], n);
        cout<<endl;
    }
}