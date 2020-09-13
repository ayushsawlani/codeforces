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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
int main()
{
    //fastio
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ve <ll> stac;
    if(sz(s)%2)
    {
        cout<<-1<<endl;
        return 0;
    }
    ll count=0;
    fr(i, 0, sz(s)-1)
        if(s[i]==')')
            count++;
    if(2*count!=sz(s))
    {
        cout<<-1<<endl;
        return 0;
    }
    ll ans=0;
    ve <ll> util(n, -1);
    if(s[0]=='(')
        util[0]=1;
    fr(i, 1, n-1)
    {
        if(s[i]=='(')
        {
            util[i]=1+util[i-1];
        }
        else
        {
            util[i]=util[i-1]-1;
        }
        
    }
    ll len=0;
    fr(i, 0, n-1)
    {
        if(util[i]>0)
        {
            len=0;
        }
        else if(util[i]<0)
        {
            len++;
        }
        else
        {
            if(len)
                ans+=len+1;
            len=0;
        }
    }
    cout<<ans<<endl;
}