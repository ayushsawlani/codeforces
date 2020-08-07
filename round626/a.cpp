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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ve <ll> in(n);
        inarr(i, in,n);
        if(n==1)
        {
            if(in[0]%2)
            {
                cout<<-1<<endl;
                continue;
            }
        }
        ve <ll> util1, util2;
        fr(i, 0, n-1)
        {
            if(sz(util1)==0)
            {
                if(in[i]%2==0)
                    util1.pb(i+1);
            }
            if(sz(util2)<2)
            {
                if(in[1]%2==1)
                    util2.pb(i+1);
            }
        }
        if(sz(util1))
        {
            cout<<1<<endl;
            outarr(i, util1, 1);
        }
        else
        {
            cout<<2<<endl;
            outarr(i, util2, 2);
        }
        cout<<endl;
    }   
}