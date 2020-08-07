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
vector <pair <char,ll>> compress_array(string a, ll n)
{
    vector <pair <char,ll>> ans;
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
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll n=sz(s);
        ve <pair <char,ll>> util=compress_array(s, sz(s));
        set <char> temp;
        ll ans=inf;
        char fir=' ', sec=' ', thir=' ';
        fr(i, 0, sz(util)-1)
        {
            fir=sec;
            sec=thir;
            thir=util[i].fi;
            temp.insert(util[i].fi);
            if(sz(temp)==3)
            {
                ans=min(ans, util[i-1].se+2);
                temp.clear();
                temp.insert(sec);
                temp.insert(thir);
            }
        }
        if(ans==inf)
        {
            cout<<"0"<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
}