#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ceil (ll)ceil
#define ll int
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
//#define ll long long int
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
//const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
int main()
{
    fastio
    ll n, m, k;
    cin>>n>>m>>k;
    ve <ve <bool>> in(n, ve <bool> (m, false));
    fr(i, 0, n-1)
    {
        string _t;
        cin>>_t;
        fr(j, 0, m-1)
        {
            if(_t[j]=='*')
            {
                in[i][j]=true;
            }
        }
    }
    ll cou=0;
    fr(x, 1, min((n-1)/2, (m-1)/2))
    {
        fr(i, x, n-1-x)
        {
            fr(j, x, m-1-x)
            {
                if((in[i][j])&&(in[i][j-x])&&(in[i][j+x])&&(in[i-x][j])&&(in[i+x][j]))
                {
                    cou++;
                }
                if(cou==k)
                {
                    cout<<i+1<<" "<<j+1<<endl;
                    cout<<i-x+1<<" "<<j+1<<endl;
                    cout<<i+x+1<<" "<<j+1<<endl;
                    cout<<i+1<<" "<<j-x+1<<endl;
                    cout<<i+1<<" "<<j+x+1<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<-1<<endl;
}