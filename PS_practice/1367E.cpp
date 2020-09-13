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
        ll n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        ve <ll> cou(26, 0);
        fr(i, 0, n-1)
        {
            cou[s[i]-'a']++;
        }
        ll ans=1;
        ve <ll> fac;
        fr(i, 1, sqrt(k))
        {
            if((k%i)==0)
            {
                fac.pb(i);
                if(i!=k/i)
                {
                    fac.pb(k/i);
                }
            }
        }
        //outarr(i, cou, 25);
        for(auto f:fac)
        {
            fr(i, 1, n/f)
            {
                ll x=0;
                fr(j, 0, 25)
                {
                    x+=(cou[j]/i);
                }
                if(x>=f)
                {
                    ans=max(i*f, ans);
                }
            }
        }
        cout<<ans<<endl;
    }
}