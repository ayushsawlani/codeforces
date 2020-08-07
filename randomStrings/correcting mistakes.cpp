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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
int main()
{
    //fastio
    ll n;
    cin>>n;
    string s1, s2;
    cin>>s1>>s2;
    ve <ll> c1(26, 0), c2(26, 0);
    fr(i, 0, n-1)
    {
        c1[s1[i]-'a']++;
        c2[s2[i]-'a']++;
    }
    ll i1=0, j1=n-1;
    ll i2=0, j2=n-1;
    while((s1[i1]==s2[i2])&&(i1<n))
    {
        i1++;
        i2++;
    }
    while((s1[j1]==s2[j2])&&(j1>i1))
    {
        j1--;
        j2--;
    }
    ll ans=0;
    ll i=i1+1;
    while((i<=j1)&&(s1[i]==s2[i-1]))
    {
        i++;
    }
    if(i>j1)
        ans++;
    i=i1;
    while((i<j1)&&(s1[i]==s2[i+1]))
    {
        i++;
    }
    if(i==j1)
        ans++;
    cout<<ans<<endl;
}