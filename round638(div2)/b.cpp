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
    fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, k;
        cin>>n>>k;
        ve <ll> in(n);
        inarr(i, in, n);
        ve <ll> co(n+1);
        ll diff=0;
        ve <ll> imp;
        fr(i, 0, n-1)
        {
            if(co[in[i]]==0)
            {
                diff++;
                imp.pb(in[i]);
            }
            co[in[i]]++;
        }
        if(diff>k)
        {
            cout<<-1<<endl;
            continue;
        }
        ll i=1;
        while((sz(imp)<k)&&(i<=n))
        {
            if(co[i]==0)
                imp.pb(i);
            i++;
        }
        cout<<k*n<<endl;
        fr(i, 0, n-1)
        {
            for(auto j: imp)
            {
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
}