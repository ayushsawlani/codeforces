#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
#define fr(i, a, b); for (int i = a; i < b; i++)
#define frn(i, a, b); for (int i = a; i > b; i--)
#define mk make_pair
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
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
        inarr(i,in,n);
        ll k=1;
        fr(i,1,n)
        {
            if(in[i]!=in[i-1])
                k=2;
        }
        if(k==1)
        {
            cout<<1<<endl;
            fr(i,0,n)
            {
                cout<<"1 ";
            }
            cout<<endl;
            continue;
        }
        if(n%2==0)
        {

            cout<<2<<endl;
            fr(i,0,n/2)
            {
                cout<<"1 2 ";
            }
            cout<<endl;
        }
        else
        {
            k=3;
            ll j=-1;
            fr(i,0,n)
            {
                if(in[i]==in[(i-1+n)%n])
                {
                    j=i;
                    k=2;
                }
            }
            if(k==3)
            {
                cout<<k<<endl;
                fr(i,0,n-1)
                {
                    cout<<1+i%2<<" ";
                }
                cout<<3<<endl;
            }
            else
            {
                cout<<2<<endl;
                fr(i,0,j)
                {
                    cout<<1+i%2<<" ";
                }
                fr(i,j,n)
                {
                    cout<<1+(i-1+2)%2<<" ";
                }
                cout<<endl;
            }
            
        }
        
    }
}