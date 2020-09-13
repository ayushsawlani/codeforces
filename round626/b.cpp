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
vector <pair <ll,ll>> compress_array(vector <ll> a, ll n)
{
    vector <pair <ll,ll>> ans;
    ll i=0;
    ll c=1;
    while(i<n-1)
    {
        if(a[i]!=a[i+1])
        {
            if(a[i]==1)
            {
                pair <ll,ll> temp;
                temp.first=a[i];
                temp.second=c;
                ans.push_back(temp);
            }
            c=1;
        }
        else
        {
            c++;
        }
        i++;   
    }
    if(a[i]==1)
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
    ll n, m, k;
    cin>>n>>m>>k;
    ve <ll> a(n), b(m);
    inarr(i, a, n);
    inarr(i, b, m);
    ve <pair <ll,ll>> coma=compress_array(a, n);
    ve <pair <ll,ll>> comb=compress_array(b, m);
    ll ans=0;
    ve <ll> fac;
    fr(i, 1, sqrt(k))
    {
        if(k%i==0)
        {
            fac.pb(i);
            if(i!=k/i)
                fac.pb(k/i);
        }
    }
    map <ll,ll> count, lencount;
    fr(i, 0, sz(coma)-1)
    {
        if(lencount.find(coma[i].se)!=lencount.end())
        {
            lencount[coma[i].se]++;
        }
        else
        {
            count[coma[i].se]=0;
            lencount[coma[i].se]=1;
            fr(j, 0, sz(comb)-1)
            {
                ll len=comb[j].se;
                ll bre=coma[i].se;
                fr(l, 0, sz(fac)-1)
                {
                    count[coma[i].se]+=(max(bre-fac[l]+1,(ll)0)*max(len-(k/fac[l])+1,(ll)0));
                }
            }
            
        }
    }
    for(auto i: lencount)
    {
        ans+=lencount[i.fi]*count[i.fi];
    } 
    cout<<ans<<endl;
}