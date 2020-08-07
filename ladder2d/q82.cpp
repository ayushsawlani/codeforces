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
    ll n, k, p;
    cin>>n>>k>>p;
    while(p--)
    {
        ll pos;
        cin>>pos;
        if(n<2*k)
        {
            if(pos>2*(n-k))
            {
                cout<<"X";
            }
            else
            {
                if(pos%2)
                {
                    cout<<".";
                }
                else
                {
                    cout<<"X";
                }
            }
        }
        else
        {
            if(n%2==0)
            {
                if(pos>n-2*k)
                {
                    if(pos%2)
                    {
                        cout<<".";
                    }
                    else
                    {
                        cout<<"X";
                   }
                }
                else
                {
                    cout<<".";
                }
            }
            else
            {
                ll _k=k-1;
                ll _n=n-1;
                if(pos<=_n)
                {
                    if(pos>_n-2*_k)
                    {
                        if(pos%2)
                        {
                            cout<<".";
                        }
                        else
                        {
                            cout<<"X";
                        }
                    }
                    else
                    {
                        cout<<".";
                    }
                }
                if(pos==_n+1)
                {
                    if(k)
                        cout<<"X";
                    else
                    {
                        cout<<".";
                    }
                    
                }
            }
            
        }
        
    }
}