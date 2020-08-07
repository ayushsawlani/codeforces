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
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
int main()
{
    ll s=1e6;
    fastio
    ll n;
    cin>>n;
    set <ll> in;
    fr(i, 0, n)
    {
        ll temp;
        cin>>temp;
        in.insert(temp);
    }
    set <ll> ans;
    ll count=0;
    for(auto i: in)
    {
        if(in.find(s-i+1)==in.end())
        {
            ans.insert(s-i+1);
        }
        else
        {
            count++;
        }
    }
    count=count/2;
    fr(i, 1, s+1)
    {
        if(count==0)
            break;
        if((in.find(i)==in.end())&&(in.find(s-i+1)==in.end()))
        {
            ans.insert(i);
            ans.insert(s-i+1);
            count--;
        }
    }
    cout<<sz(ans)<<endl;
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}