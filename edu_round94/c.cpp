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
        string s;
        cin>>s;
        ll x;
        cin>>x;
        ll n=sz(s);
        ve <ll> ans(n, 1);
        fr(i, 0, n-1)
        {
            if(s[i]=='0')
            {
                if(i+x<n)
                    ans[i+x]=0;
                if(i-x>=0)
                {
                    ans[i-x]=0;
                }
            }
        }
        ll check=0;
        fr(i, 0, n-1)
        {
            if(s[i]=='1')
            {
                ll ok=0;
                if(i+x<n)
                {
                    if(ans[i+x]==1)
                        ok=1;
                }
                if(i-x>=0)
                {
                    if(ans[i-x]==1)
                        ok=1;
                }
                if(ok==0)
                    check=1;
            }
        }
        if(check)
            cout<<-1<<endl;
        else
        {
            fr(i, 0, n-1)
                cout<<ans[i];
            cout<<endl;
        }
        
    }
}