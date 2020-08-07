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
    ll k;
    cin>>k;
    cout<<4<<" "<<4<<endl;
    ve <ve <ll>> ans(4);
    fr(i,0,4)
    {
        ans[i]=(*new ve <ll>(4));
    }
    ll oneforall=pow(2,18)-1;
    ll allforone=pow(2,17);
    fr(i,0,2)
    {
        fr(j,0,2)
            ans[i][j]=oneforall;
    }
    ans[2][0]=oneforall;
    ans[2][1]=allforone;
    ans[3][0]=k;
    ans[3][1]=oneforall;
    ans[0][2]=oneforall;
    ans[1][2]=k;
    ans[0][3]=allforone;
    ans[1][3]=oneforall;
    ans[2][2]=oneforall;
    ans[3][2]=oneforall;
    ans[2][3]=oneforall;
    ans[3][3]=k;
    fr(i,0,4)
    {
        outarr(j,ans[i],4);
        cout<<endl;
    }
}