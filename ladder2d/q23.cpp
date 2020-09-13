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
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
ve <ve <ll>> dp1(5003,ve <ll>(5003,0));
int main()
{
    fastio
    ll n,m;
    cin>>n>>m;
    ve <ve <ll>> in(n,ve <ll>(m));
    fr(i,0,n)
    {
        string s;
        cin>>s;
        fr(j,0,m)
        {
            if(s[j]=='0')
            {
                in[i][j]=0;
            }
            else
            {
                in[i][j]=1;
            }
        }
    }
    fr (i,0,n)
    {
        fr(j,0,m)
        {
            if(in[i][j]==1)
            {
                dp1[i][j]=(j>0?dp1[i][j-1]:0)+1;
            }
        }
    }
    ll ans=0;
    fr(i,0,m)
    {
        ve <ll> count(m+5,0);
        fr(j,0,n)
        {
            count[dp1[j][i]]++;
        }
        ve <ll> temp(n);
        ll temp_i=0;
        fr(j,0,m+5)
        {
            fr(k,0,count[j])
            {
                temp[temp_i++]=j;
            }
        }
        fr(i,0,n)
        {
            ans=max(ans,temp[i]*(n-i));
        }
    }
    cout<<ans<<endl;
}