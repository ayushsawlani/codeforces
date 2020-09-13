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
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
int main()
{
    //fastio
    ll n, m;
    cin>>n>>m;
    ve <ll> jiroat,jirodef, ceil(m);
    ve <pair <ll,ll>> jirotot;
    fr(i, 0, n)
    {
        string ch;
        ll str;
        cin>>ch>>str;
        ll type=0;
        if(ch=="ATK")
            jiroat.pb(str);
        else
        {
            jirodef.pb(str);
            type=1;
        }
        jirotot.pb(pair <ll,ll>(str, type));
    }
    inarr(i, ceil, m);
    sort(jiroat.begin(), jiroat.end());
    sort(jirodef.begin(), jirodef.end());
    sort(jirotot.begin(), jirotot.end());
    sort(ceil.begin(), ceil.end());
    ll flag=0;
    ll ans=0;
    if(m>=n)
    {
        ll j=n-1;
        ll i=m-1;
        while(i>-1)
        {
            if(j==-1)
                break;
            if(jirotot[j].se==1)
            {
                if(ceil[i]<=jirotot[j].fi)
                {
                    flag=1;
                    break;
                }
            }
            else
            {
                if(ceil[i]<jirotot[j].fi)
                {
                    flag=1;
                    break;
                }
            }
            j--;
            i--;
        }
        if(flag==0)
        {
            fr(i, 0, m)
                ans+=ceil[i];
            fr(j, 0, sz(jiroat))
            {
                ans-=jiroat[j];
            }
            set <pair <ll,ll>> util;
            fr(i, 0, m)
                util.insert(pair<ll,ll> (ceil[i],i));
            fr(i, 0, sz(jirodef))
            {
                auto it=util.lower_bound(pair <ll,ll> (jirodef[i], inf));
                ans-=it->fi;
                util.erase(it);
            }
        }
    }
    else
    {
        flag=1;
    }
    if(flag==1)
        ans=0;
    ll ans1=0;
    ll j=0;
    frn(i, m-1, -1)
    {
        if(j==sz(jiroat))
            break;
        ans1+=max(ceil[i]-jiroat[j], (ll)0);
        j++;
    }
    cout<<max(ans, ans1)<<endl;
}