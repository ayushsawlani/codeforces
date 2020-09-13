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
        ll n, k;
        cin>>n>>k;
        ve <ll> arr(n);
        inarr(i, arr, n);
        if(n==1)
        {
            if(arr[0]==k)
                cout<<"yes"<<endl;
            else
            {
                cout<<"no"<<endl;
            }
            continue;
        }
        ve <ll> in(n);
        ve <ll> insum(n);
        ve <ll> zero;
        ve <ve <ll>> imp(2*n+10);
        fr(i, 0, n-1)
        {
            if(arr[i]>k)
            {
                in[i]=1;
            }
            if(arr[i]<k)
            {
                in[i]=-1;
            }
            if(arr[i]==k)
            {
                in[i]=0;
                zero.pb(i);
            }
            insum[i]=in[i];
            if(i>0)
            {
                insum[i]=insum[i-1]+in[i];
            }
            imp[n+1+insum[i]].pb(i);
        }
        //cout<<"x"<<endl;
        string ans="no";
        if(sz(zero)==0)
        {
            cout<<ans<<endl;
            continue;
        }
        fr(i, 0, n-2)
        {
            if((in[i]>=0)&&(in[i+1]>=0))
                ans="yes";
        }
        fr(i, 0, n-3)
        {
            if((in[i]>=0)&&(in[i+2]>=0))
                ans="yes";
        }
       cout<<ans<<endl;
        //*/ 
    }
}