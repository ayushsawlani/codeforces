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
    fastio
    ll n, m;
    cin>>n>>m;
    if((n==2)&&(m==1))
    {
        cout<<0<<endl;
        cout<<1<<" "<<1<<endl;
        cout<<2<<" "<<1<<endl;
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    if((n==1)&&(m==2))
    {
        cout<<0<<endl;
        cout<<1<<" "<<1<<endl;
        cout<<1<<" "<<2<<endl;
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    if((n%2==0)&&(m>1))
    {
        cout<<0<<endl;
        cout<<1<<" "<<1<<endl;
        fr(i, 1, n)
        {
            fr(j, 2, m)
            {
                if(i%2)
                {
                    cout<<i<<" "<<j<<endl;
                }
                else
                {
                    cout<<i<<" "<<m-j+2<<endl;
                }
            }
        }
        frn(i, n, 1)
        {
            cout<<i<<" "<<1<<endl;
        }
        return 0;
    }
    if((m%2==0)&&(n>1))
    {
        cout<<0<<endl;
        cout<<1<<" "<<1<<endl;
        fr(i, 1, m)
        {
            fr(j, 2, n)
            {
                if(i%2)
                {
                    cout<<j<<" "<<i<<endl;
                }
                else
                {
                    cout<<n-j+2<<" "<<i<<endl;
                }
            }
        }
        frn(i, m, 1)
        {
            cout<<1<<" "<<i<<endl;
        }
        return 0;
    }
    cout<<1<<endl;
    cout<<n<<" "<<m<<" "<<1<<" "<<1<<endl;
    fr(i, 1, n)
    {
        fr(j, 1, m)
        {
            if(i%2)
            {
                cout<<i<<" "<<j<<endl;
            }
            else
            {
                cout<<i<<" "<<m-j+1<<endl;
            }
        }
    }
    cout<<1<<" "<<1<<endl;
}