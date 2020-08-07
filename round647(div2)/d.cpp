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
int main()
{
    //fastio
    ll n, m;
    cin>>n>>m;
    ve <ve <ll>> G(n);
    fr(i, 0, m-1)
    {
        ll a, b;
        cin>>a>>b;
        a--;
        b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    ve <ll> des(n);
    inarr(i, des, n);
    set <ll> imp, imp1;
    ve<pair <ll,ll>> i_m;
    fr(i, 0, n-1)
    {
        i_m.pb(mk(des[i], i));
    }
    sort(all(i_m));
    ll i=0;
    ve <ll> ans;
    while(i<n)
    {
        set <ll> te;
        for(auto j:G[i_m[i].se])
        {
            te.insert(des[j]);
        }
        ll curr=1;
        for(auto ele:te)
        {
            if(curr!=ele)
                break;
            curr++;
        }
        if(curr!=i_m[i].fi)
        {
            cout<<-1<<endl;
            return 0;
        }
        ans.pb(i_m[i].se+1);
        i++;
    }
    if(sz(ans)!=n)
    {
        cout<<-1<<endl;
        return 0;
    }
    outarr(i, ans, n);
    cout<<endl;
}