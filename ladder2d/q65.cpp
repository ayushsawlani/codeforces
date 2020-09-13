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
#define ceil (int)ceil
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
ll solve(string &s, ve <pair <ll,ll>> &struc, ll cou, ll k)
{
    if(cou==k)
    {
        return k;   
    }
    ll n=sz(s);
    fr(i, 0, 25)
    {
        if(cou==k)
            return k;
        ve <pair <ll,ll>> tovis;
        for(auto it:struc)
        {
            if(it.se<n-1)
            {
                if(s[it.se+1]==i+'a')
                {
                    cou++;
                    tovis.pb(mk(it.fi, it.se+1));
                    if(cou==k)
                    {
                        fr(pr, it.fi, it.se+1)
                        {
                            cout<<s[pr];
                        }
                        cout<<endl;
                        return k;
                    }
                }
            }
        }
        if(sz(tovis))
            cou=solve(s, tovis, cou, k);
    }
    return cou;
}
int main()
{
    //fastio
    string s;
    cin>>s;
    ll n=sz(s);
    ll k;
    cin>>k;
    ve <pair <ll,ll>> ini;
    fr(i, 0, n-1)
    {
        ini.pb(mk(i, i-1));
    }
    ll ans=solve(s, ini, 0, k);
    if(ans<k)
        cout<<"No such line."<<endl; 
}