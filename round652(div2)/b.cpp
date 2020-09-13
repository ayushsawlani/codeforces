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
vector <pair <ll,ll>> compress_array(string a, ll n)
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
    if(i<n)
    {
        pair <ll,ll> temp;
        temp.first=a[i];
        temp.second=c;
        ans.push_back(temp);
        c=1;
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
        ll n;
        cin>>n;
        cin>>s;
        string ans;
        ll it=0;
        while((s[it]=='0')&&(it<n))
        {
            ans.pb(s[it]);
            it++;
        }
        ve <ll> carr(n, 0);
        if(s[n-1]=='0')
            carr[n-1]++;
        frn(i, n-2, 0)
        {
            carr[i]=carr[i+1];
            if(s[i]=='0')
                carr[i]++;
        }
        ll it2=it;
        while((carr[it2]>0)&&(it2<n))
        {
            it2++;
        }
        if(it2!=it)
            ans.pb('0');
        while(it2<n)
            ans.pb(s[it2++]);
        cout<<ans<<endl;
    }
}