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
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        if((n*m)%2==0)
        {
            if(n%2==0)
            {
                fr(i,0,m)
                    cout<<"B";
                cout<<endl;
                cout<<"B";
                fr(i,0,m-1)
                    cout<<"W";
                cout<<endl;
                fr(i,0,n-2)
                {
                    fr(j,0,m)
                    {
                        if(i%2==0)
                            cout<<"B";
                        else
                        {
                            cout<<"W";
                        }
                    }
                    cout<<endl;
                }
            }
            else
            {
                fr(i,0,n-1)
                {
                    fr(j,0,m)
                    {
                        if(j%2==0)
                            cout<<"B";
                        else
                        {
                            cout<<"W";
                        }
                    }
                    cout<<endl;
                }
                cout<<"B";
                fr(i,0,m-1)
                {
                    if(i%2==0)
                        cout<<"B";
                    else
                    {
                        cout<<"W";
                    }
                }
                cout<<endl;
                    
            }
            
        }
        else
        {
            fr(i,0,n-1)
            {
                fr(j,0,m)
                {
                    if(i%2==0)
                        cout<<"B";
                    else
                    {
                        cout<<"W";
                    }
                }
                cout<<endl;
            }
            fr(i,0,m)
            {
                if(i%2==0)
                    cout<<"B";
                else
                {
                    cout<<"W";
                }
            }
            cout<<endl;
        }
        
    }
}