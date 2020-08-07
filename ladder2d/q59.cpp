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
    ll n, k;
    cin>>n>>k;
    ve <ll> in(n), inv(n), out(n);
    inarr(i, in, n);
    inarr(i, out, n);
    ve <ll> _in(n), __in(n);
    fr(i, 0, n-1)
    {
        __in[i]=i+1;
        inv[in[i]-1]=i+1;
    }
    ll pow1=inf;
    if(__in==out)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    fr(j, 0, k-1)
    {
        fr(i, 0, n-1)
        {
            _in[i]=__in[in[i]-1];
        }
        __in=_in;
        if((__in==out)&&(pow1==inf))
        {
            pow1=j+1;
        }
   }
    //outarr(i, __in, n);
    //cout<<endl;
    string ans="NO";    
    //cout<<pow<<" "<<cyc<<endl;
    fr(i, 0, n-1)
    {
        __in[i]=i+1;
    }
    ll pow2=inf;
    if(__in==out)
    {
        pow2==0;
    }
    fr(j, 0, k-1)
    {
        fr(i, 0, n-1)
        {
            _in[in[i]-1]=__in[i];
        }
        __in=_in;
        if((__in==out)&&(pow2==inf))
        {
            pow2=j+1;
        }
   }
   if((k==pow1)||(k==pow2))
   {
       ans="YES";
   }
   else if(((k-pow1)%2==0)&&(pow1!=inf))
   {
       if((pow2>1)||(pow1>1))
       {
           ans="YES";
       }
   }
    else if(((k-pow2)%2==0)&&(pow2!=inf))
   {
       if((pow1>1)||(pow2>1))
       {
           ans="YES";
       }
   }
  // outarr(i, __in, n);
   // cout<<endl; 
   //cout<<pow<<" "<<cyc<<endl;
    cout<<ans<<endl;
}