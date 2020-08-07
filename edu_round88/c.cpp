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
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e10;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
ld func(ld x, ld h, ld c)
{
    return (x*h+(x-1)*c)/(2*x-1);
}
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ld h, c, t;
        cin>>h>>c>>t;
        if(t<=(h+c)/2)
        {
            cout<<2<<endl;
            continue;
        }
        ll i=1;
        ll j=inf;
        while(i<j)
        {
            ll mid=((i+j+1)/2);
            if(func(mid, h, c)>=t)
            {
                i=mid;
            }
            else
            {
                j=mid-1;
            }
        }
        if(abs(func(i+1, h, c)-t)<abs(func(i, h, c)-t))
        {
            i++;
        }
        cout<<2*i-1<<endl;
    }
}