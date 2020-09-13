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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, m;
        cin>>n>>m;
        ve <ve <ll>> in(n, ve<ll>(m));
        fr(i, 0 ,n-1)
        {
            inarr(j, in[i], m);
        }
        ll ans=0;
        fr(dist, 0, (n+m-3)/2)
        {
            ll c1=0;
            ll c2=0;
            fr(j, 0, n-1)
            {
                ll i=dist-j;
                if((i<m)&&(i>=0))
                {
                    if(in[j][i])
                    {
                        c1++;
                    }
                    else
                    {
                        c2++;
                    }
                }
                i=n+m-2-j-dist;
                if((i<m)&&(i>=0))
                {
                    if(in[j][i])
                    {
                        c1++;
                    }
                    else
                    {
                        c2++;
                    }
                }
            }   
            ans+=min(c1, c2);
        }
        cout<<ans<<endl;
    }
}