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
        ve <ll> in(2*n);
        inarr(i, in, 2*n);
        ve <ll> odd, even;
        fr(i, 0, 2*n-1)
        {
            if(in[i]%2)
            {
                odd.pb(i);
            }
            else
            {
                even.pb(i);
            }
        }
        ve <ll> ans;    
        if((sz(odd)%2))
        {
            odd.pop_back();
            even.pop_back();
        }
        else if(sz(odd))
        {
            odd.pop_back();
            odd.pop_back();
        }
        else
        {
            even.pop_back();
            even.pop_back();
        }
        fr(i, 0, sz(even)-2)
        {
            cout<<even[i]+1<<" "<<even[i+1]+1<<endl;
            i++;
        }
        fr(i, 0, sz(odd)-2)
        {
            cout<<odd[i]+1<<" "<<odd[i+1]+1<<endl;
            i++;
        }
    }
}