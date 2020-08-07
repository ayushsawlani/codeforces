#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ceil (int)ceil
#define ll int
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
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve <ll> ans(4*n, -1);
    fr(i, 0, n-1)
    {
        ans[i]=i+1;
    }
    ll end=n-1;
    fr(x, 1, n)
    {
        ll k=(n/x)*x+end-n+1;
        if(n%x==0)
            k-=x;
        ll _t;
        swap(ans[k], ans[end+1], _t);
        k-=x;
        for(;k>=end-n+1;k-=x)
        {
            swap(ans[k], ans[k+x], _t);
        }
        end++;
        /*fr(i, 0, 4*n-1)
        {
            if(ans[i]!=-1)
            {
                cout<<ans[i]<<" ";
            }
        }
        cout<<endl;
        //*/
    }
    fr(i, 0, 4*n-1)
    {
        if(ans[i]!=-1)
        {
            cout<<ans[i]<<" ";
        }
    }
    cout<<endl;
}