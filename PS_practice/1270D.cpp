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
void ask(set <ll> que)
{
    cout<<"? ";
    for(auto it:que)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    cout.flush();
}
void ans(ll x)
{
    cout<<"! "<<x;
    cout.flush();
}
int main()
{
    //fastio
    ll n, k;
    cin>>n>>k;
    set <ll> yo;
    fr(i, 0, k-1)
    {
        yo.insert(i+1);
    }
    ve <pair <ll,ll>> list(k+1);
    ask(yo);
    cin>>list[0].fi>>list[0].se;
    auto it1=yo.find(1);
    yo.erase(it1);
    yo.insert(k+1);
    fr(i, 1, k)
    {
        ask(yo);
        cin>>list[i].fi>>list[i].se;
        auto it1=yo.find(i+1);
        yo.erase(it1);
        yo.insert(i);
    }
    ll cou=0;
    fr(i, 1, k)
    {
        if(list[i].fi==list[0].fi)
            cou++;
    }
    if(list[0].se<list[list[0].fi].se)
    {
        ans(k-cou);
    }
    else
    {
        ans(cou+1);
    }
}