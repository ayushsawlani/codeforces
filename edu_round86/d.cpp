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
    ll n,k;
    cin>>n>>k;
    ve <ll> in(n);
    inarr(i, in, n);
    ve <ll> c(k);
    inarr(i, c, k);
    sort(in.begin(), in.end());
    set <pair<ll,ll>> imp;
    map<ll,ll> count;
    ll co=1;
    fr(i, 0, n-2)
    {
        if(in[i]==in[i+1])
        {
            co++;
        }
        else
        {
            imp.insert(pair <ll,ll>(c[in[i]-1],-in[i]));
            count[in[i]]=co;
            co=1;
        }
        
    }
    imp.insert(pair <ll,ll> (c[in[n-1]-1], -in[n-1]));
    count[in[n-1]]=co;
    ve <ve <ll>> ans;
    while(imp.empty()==false)
    {
        ve <ll> tobepu;
        while(1)
        {
            auto it=imp.lower_bound(pair <ll,ll> (sz(tobepu)+1,-inf));
            if(it==imp.end())
                break;
            ll num=min(it->fi-sz(tobepu),count[-it->se]);
            fr(i, 1, num)
            {
                tobepu.pb(-it->se);
            }
            count[-it->se]-=num;
            if(count[-it->se]==0)
            {
                imp.erase(it);
            }
        }
        ans.pb(tobepu);
    }
    cout<<sz(ans)<<endl;
    fr(i, 0, sz(ans)-1)
    {
        cout<<sz(ans[i])<<" ";
        outarr(j , ans[i], sz(ans[i]));
        cout<<endl;
    }
}