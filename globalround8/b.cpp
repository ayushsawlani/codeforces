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
int main()
{
    //fastio
    string s="codeforces";
    ll k;
    cin>>k;
    if(k==1)
    {
        cout<<s<<endl;
        return 0;
    }
    ll i=1;
    while(pow(i, 10)<k)
    {
        i++;
    }
    i--;
    ll ans=10*i;
    ll num=pow(i, 10);
    ll c=0;
    while(num<k)
    {
        num=num/i;
        num=num*(i+1);
        c++;
    }
    fr(j, 0, c-1)
    {
        fr(it, 0, i)
        {
            cout<<s[j];
        }
    }
    fr(j, c, 9)
    {
        fr(it, 0, i-1)
        {
            cout<<s[j];
        }
    }
    cout<<endl;
}