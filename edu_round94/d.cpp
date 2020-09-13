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
        ll n;
        cin>>n;
        ve <ll> in(n);
        inarr(i, in, n);
        ve <ve <ll>> cou(n+1, ve <ll> (n, 0));
        fr(i, 1, n)
        {
            if(in[0]==i)
            {
                cou[i][0]++;
            }
            fr(j, 1, n-1)
            {
                cou[i][j]=cou[i][j-1];
                if(in[j]==i)
                    cou[i][j]++;
            }
        }
        //cout<<cou[2][1]<<endl;
        ll ans=0;
        fr(l, 3, n-1)
        {
            ll cur=0;
            frn(j, l-1, 2)
            {
                cur-=(cou[in[j-1]][l-1]-cou[in[j-1]][j]);
                cur+=(cou[in[j]][j-2]);
                if(in[j-1]==in[l])
                    ans+=cur;
                //cout<<l<<" "<<j<<" "<<cur<<endl;
            }
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
}