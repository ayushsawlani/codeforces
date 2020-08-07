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
    ve <ll> in(m);
    inarr(i,in,m);
    ll sum=0;
    fr(i,0,m)
    {
        sum+=in[i];
    }
    if(sum<n)
    {
        cout<<-1<<endl;
        return 0;
    }
    fr(i,1,m)
    {
        if(in[i]+i>n)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    ll i=n;
    ll j=m-1;
    ve <ll> ans(m,-1);
    while(i>0)
    {
        i=i-in[j];
        j--;
        if(i<=j)
        {
            j++;
            i+=in[j];
            break;
        }
        else
        {
            ans[j+1]=i+1;
        }
    }
    fr(i,0,j+1)
    {
        ans[i]=i+1;
    }
    outarr(i,ans,m);
    cout<<endl;
}