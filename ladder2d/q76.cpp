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
int main()
{
    //fastio
    ll n, m;
    cin>>n>>m;
    ve <ve <ll>> in(n);
    fr(i, 0, n-1)
    {
        ll _t;
        cin>>_t;
        while(_t--)
        {
            ll el;
            cin>>el;
            in[i].pb(el);
        }
    }
    ve <ll> final(m);
    inarr(i, final, m);
    ve <ll> maxsumsubarry(n, -inf),maxprein(n, -inf), maxsufin(n, -inf), sumin(n);
    ll ans=-inf;
    fr(i, 0, n-1)
    {
        ll s1=in[i][0];
        ll s2=in[i][sz(in[i])-1];
        maxprein[i]=max(maxprein[i], s1);
        maxsufin[i]=max(maxsufin[i], s2);
        fr(j, 1, sz(in[i])-1)
        {
            s1+=in[i][j];
            s2+=in[i][sz(in[i])-1-j];
            maxprein[i]=max(maxprein[i], s1);
            maxsufin[i]=max(maxsufin[i], s2);
        }
        sumin[i]=s1;
        s1=0;
        fr(j, 0, sz(in[i])-1)
        {
            s1+=in[i][j];
            maxsumsubarry[i]=max(maxsumsubarry[i], s1);
            if(s1<0)
            {
                s1=0;
            }
        }
    }
    ve <ll> prefinal(m);
    prefinal[0]=sumin[final[0]-1];
    fr(i, 1, m-1)
    {
        prefinal[i]=prefinal[i-1]+sumin[final[i]-1];
    }
    ve <ll> util(m);
    frn(i, m-1, 1)
    {
        util[i]=maxprein[final[i]-1]+prefinal[i-1];
        if(i<m-1)
        {
            util[i]=max(util[i], util[i+1]);
        }
    }
    fr(i, 0, m-2)
    {
        ans=max(ans, maxsufin[final[i]-1]-prefinal[i]+util[i+1]);
    }
    fr(i, 0, m-1)
    {
        ans=max(ans, maxsumsubarry[final[i]-1]);
    }
    cout<<ans<<endl;
}