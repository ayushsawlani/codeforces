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
    ll u,v;
    cin>>u>>v;
    if(u>v)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(u==0)
    {
        if(v==0)
        {
            cout<<0<<endl;
            return 0;
        }
        else if(v==1)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    if(u==v)
    {
        cout<<1<<endl<<u<<endl;
        return 0;
    }
    if((u-v)%2==0)
    {
        ll a=u;
        ll b=(v-u)/2;
        ll c=(v-u)/2;
        if((a^c)==a+c)
        {
            cout<<2<<endl<<a+c<<" "<<c<<endl;
        }
        else
        {
            cout<<3<<endl<<a<<" "<<b<<" "<<c<<endl;
        }
    }
    else
    {
        cout<<-1<<endl;
    }
}