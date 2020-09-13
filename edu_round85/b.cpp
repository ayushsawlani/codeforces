#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
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
        ll n,x;
        cin>>n>>x;
        ve<ll>in(n);
        inarr(i,in,n);
        sort(in.begin(), in.end());
        ll sum=0;
        ld avg;
        frn(i,n-1,-1)
        {
            sum+=in[i];
            avg=(sum/((n-i)*1.0));
            if(avg<x)
            {
                cout<<n-i-1<<endl;
                break;
            }
        }
        if(avg>=x)
            cout<<n<<endl;

    }
}