#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
int main()
{
    //fastio
    ll n,m;
    cin>>n>>m;
    ve <ve <ll>> in(n),ul(n),ur(n),dl(n),dr(n);
    fr(i,0,n)
    {
        in[i]=(*new ve<ll>(m));
        ul[i]=(*new ve<ll>(m));
        ur[i]=(*new ve<ll>(m));
        dl[i]=(*new ve<ll>(m));
        dr[i]=(*new ve<ll>(m));
    }
    fr(i,0,n)
    {
        inarr(j,in[i],m);
    }
    fr(i,0,n)
    {
        fr(j,0,m)
        {
            ul[i][j]=max(i-1>=0?ul[i-1][j]:0,j-1>=0?ul[i][j-1]:0)+in[i][j];
            ur[i][m-1-j]=max(i-1>=0?ur[i-1][m-1-j]:0,j-1>=0?ur[i][m-1-j+1]:0)+in[i][m-1-j];
            dl[n-1-i][j]=max(i-1>=0?dl[n-1-i+1][j]:0,j-1>=0?dl[n-i-1][j-1]:0)+in[n-i-1][j];
            dr[n-1-i][m-1-j]=max(i-1>=0?dr[n-1-i+1][m-1-j]:0,j-1>=0?dr[n-i-1][m-1-(j-1)]:0)+in[n-i-1][m-1-j];
        }
    }
    ll ans=-1;
    fr(i,1,n-1)
    {
        fr(j,1,m-1)
        {
            ans=max(ul[i-1][j]+dr[i+1][j]+dl[i][j-1]+ur[i][j+1],ans);
            ans=max(dl[i+1][j]+ur[i-1][j]+ul[i][j-1]+dr[i][j+1],ans);
        }
    }
    cout<<ans<<endl;
}