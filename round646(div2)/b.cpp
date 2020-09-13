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
ll calc(string &s1, string &s2)
{
    ll ans=0;
    fr(i, 0, sz(s1)-1)
    {
        if(s1[i]!=s2[i])
            ans++;
    }
    return ans;
}
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll n=sz(s);
        ve <ll> prev(n, 0);
        if(s[0]=='0')
            prev[0]++;
        fr(i, 1, n-1)
        {
            prev[i]=prev[i-1];
            if(s[i]=='0')
                prev[i]++;
        }
        ll ans=inf;
        ans=min(prev[n-1], n-prev[n-1]);
        fr(i, 1, n-1)
        {
            ans=min(prev[i-1]+n-i-(prev[n-1]-prev[i-1]), ans);
            ans=min(i-prev[i-1]+(prev[n-1]-prev[i-1]), ans);
        }
        cout<<ans<<endl;
    }
}