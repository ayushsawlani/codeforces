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
const ll inf = 1e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
int main()
{
    ll var=-inf;
    //fastio
    ll n, m, k, p;
    cin>>n>>m>>k>>p;
    ve <ve <ll>> in(n, ve <ll>(m));
    fr(i, 0, n)
    {
        inarr(j, in[i], m);
    }
    set < pair <ll,ll>> row,column;
    fr(i,0, n)
    {
        ll sum = 0;
        fr (j, 0, m)
        {
            sum+=in[i][j];
        }
        row.insert(pair <ll,ll> (sum,i));
    }
    fr(i,0, m)
    {
        ll sum = 0;
        fr (j, 0, n)
        {
            sum+=in[j][i];
        }
        column.insert(pair <ll,ll> (sum,i));
    }
    set <pair <ll,ll> > answer,answer2;
    ll sum=0;
    ll ans=-inf;
    while(sz(answer)<k)
    {
        auto it=row.end();
        it--;
        answer.insert(pair <ll,ll>((*it).first,var));
        var++;
        sum+=it->first;
        pair <ll,ll> temp(it->first-m*p,it->second);
        row.erase(it);
        row.insert(temp);
    }
    ans=max(ans,sum);
    ll rcount=k;
    ll ccount=0;
    while(ccount<k)
    {

        auto it1=answer.begin();
        auto it2=column.end();
        it2--;
        sum+=it2->first-it1->first;
        sum+=(ccount*rcount)*p;
        rcount--;
        ccount++;
        sum-=(ccount*rcount)*p;
        ans=max(ans,sum);
        answer.erase(it1);
        var++;
        pair <ll,ll> temp(it2->first-n*p,it2->second);
        column.erase(it2);
        column.insert(temp);
   }
   cout<<ans<<endl;
}