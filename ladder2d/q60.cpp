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
vector <pair <ll,ll>> compress_array(vector <ll> a, ll n)
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
    ll n, k;
    cin>>n>>k;
    ve <ll> in(n);
    ve <ll> _in(n);
    inarr(i, in, n);
    _in=in;
    sort(all(in));
    ve <pair <ll,ll>> util=compress_array(in, n);
    ll i=0;
    ll co=0;
    ll pre=0;
    while((k>=0)&&(i<sz(util)))
    {
        if(k-(n-co)*(util[i].fi-(i>0?util[i-1].fi:0))>=0)
        {
            k-=((n-co)*(util[i].fi-(i>0?util[i-1].fi:0)));
            co+=util[i].se;   
            pre=util[i].fi;
        }
        else
        {
            break;
        }
        i++;
    }
    if((i==sz(util))&&(k>0))
    {
        cout<<-1<<endl;
        return 0;
    }
    else if((i==sz(util))&&(k==0))
    {
        cout<<endl;
        return 0;
    }
    pre+=(k/(n-co));
    k%=(n-co);
    ve <ll> ans;
    fr(i, 0, n-1)
    {
        if(_in[i]>pre)
        {
            ans.pb(i+1);
        }
    }
    fr(i, 0, sz(ans)-1)
    {
        if((_in[ans[(i+k+sz(ans))%sz(ans)]-1]>pre+1)||((i+k+sz(ans))%sz(ans)>=k))
        {
            cout<<ans[(i+k+sz(ans))%sz(ans)]<<" ";
        }
    }
    cout<<endl;
}