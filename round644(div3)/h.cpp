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
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
ll toint(string s)
{
    ll x=1;
    ll ans=0;
    frn(i, sz(s)-1, 0)
    {
        ans+=x*(s[i]-'0');
        x=x*2;
    }
    return ans;   
}
ll bin(ve <ll> &arr, ll x)
{
    ll i=0;
    ll j=sz(arr)-1;
    while(i<j)
    {
        ll mid=(i+j+1)/2;
        if(arr[mid]<=x)
        {
            i=mid;
        }
        else
        {
            j=mid-1;   
        }
    }
    if(arr[i]!=x)
        return -1;
    else
    {
        return i;
    }
}
ll bin1(ve <ll> &arr,ll val)
{
    ll i=val;
    ll j=inf;
    if(bin(arr, val)==-1)
        return val;
    while(i<j)
    {
        ll mid=(i+j)/2;
        if(bin(arr, mid)==-1)
        {
            j=mid;
        }
        else
        {
            ll num=bin(arr, mid)-bin(arr, val);
            if(num<mid-val)
            {
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
            
        } 
        
    }
    return i;
}
ll bin2(ve <ll> &arr,ll val)
{
    ll i=0;
    ll j=val;
    if(bin(arr, val)==-1)
    {
        return val;
    }
    while(i<j)
    {
        ll mid=(i+j+1)/2;
        if(bin(arr, mid)==-1)
        {
            i=mid;
        }
        else
        {
            ll num=bin(arr, val)-bin(arr, mid);
            if(num<val-mid)
            {
                i=mid+1;
            }
            else
            {
                j=mid-1;
            }
            
        } 
        
    }
    return i;
}
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, m;
        cin>>n>>m;
        ve <string> _in(n);
        inarr(i, _in, n);
        ve <ll> in(n);
        fr(i, 0, n-1)
        {
            in[i]=toint(_in[i]);
        }
        sort(all(in));
        ve <ll> q;
        ll med=(pow(2, m)-1)/2;
        ll ev=1;
        fr(i, 0, n-1)
        {
            q.pb(in[i]);
            if(ev)
            {
                if(in[i]<=med)
                {
                    med=bin1(q, med+1);
                }
            }
            else
            {
                if(in[i]>=med)
                {
                    med=bin2(q, med-1);
                }   
            }
        //    cout<<med<<endl;
            ev=(ev+1)%2;
        }
        string ans="";
        fr(i, 0, m-1)
        {
            ans.pb(med%2+'0');
            med=med/2;
        }
        frn(i,m-1, 0)
        {
            cout<<ans[i];
        }
        cout<<endl;
    }
}