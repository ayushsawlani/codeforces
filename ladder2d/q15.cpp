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
#define fr(i, a, b); for (int i = a; i < b; i++)
#define frn(i, a, b); for (int i = a; i > b; i--)
#define mk make_pair
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve <ve <ll>> in(n);
    fr(i,0,n)
    {
        in[i]=(*new ve <ll> (n));
    }
    fr(i,0,n)
    {
        inarr(j,in[i],n);
    }
    ve <ll> X(n);
    inarr(i,X,n);
    fr(i,0,n)
        X[i]--;
    ve <ll> ans(n,0);
    frn(k,n-1,-1)
    {
        frn(i,n-1,-1)
        {
            frn(j,n-1,-1)
            {
                if(in[X[i]][X[k]]+in[X[k]][X[j]]<in[X[i]][X[j]])
                {
                    in[X[i]][X[j]]=in[X[i]][X[k]]+in[X[k]][X[j]];
                }
            }
        }
        frn(i,n-1,k-1)
        {
            frn(j,n-1,k-1)
            {
                ans[k]+=in[X[i]][X[j]];
            }
        }
    }
    fr(i,0,n)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}