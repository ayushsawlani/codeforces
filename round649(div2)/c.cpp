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
vector <pair <ll,ll>> compress_array(vector <ll> a, ll n)
{
    vector <pair <ll,ll>> ans;
    ll i=0;
    ll c=1;
    while(i<n-1)
    {
        if(a[i]!=a[i+1])
        {
            pair <ll,ll> temp;
            temp.first=a[i];
            temp.second=c;
            ans.push_back(temp);
            c=1;
        }
        else
        {
            c++;
        }
        i++;   
    }
    pair <ll,ll> temp;
    temp.first=a[i];
    temp.second=c;
    ans.push_back(temp);
    c=1;
    return ans;
}
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve <ll> a(n), b(n, -1), c(1e6+5, 0);
    inarr(i, a, n); 
    fr(i, 0, n-1)
    {
        c[a[i]]++;
    }
    ve <pair <ll,ll>>imp=compress_array(a, n);
    ll ptr=imp[0].se;
    fr(i, 1, sz(imp)-1)
    {
        b[ptr]=imp[i-1].fi;
        ptr+=imp[i].se;
    }
    ll yess=0;
    fr(i, 0, n-1)
    {
        while(c[yess])
        {
            yess++;
        }
        if(b[i]==-1)
        {
            b[i]=yess;
            yess++;
        }
    }
    if(yess==1e6+1)
    {
        cout<<-1<<endl;
        return 0;
    }
    fr(i, 0, n-1)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
}