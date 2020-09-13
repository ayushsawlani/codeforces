#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define pb push_back
#define mod 1000000007
#define inarr(i,arr,n); for(ll i=0;i<n;i++) cin >> arr[i];
#define outarr(i,arr,n); for(ll i=0;i<n;i++) cout<<arr[i];
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
        ll n, m, a, b;
        cin>>n>>m>>a>>b;
        if(a*n!=b*m)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        ll f=0;
        if(n>m)
        {
            ll _t;
            swap(n,m,_t);   
            swap(a,b,_t);   
            f=1;
        }
        ve <ve <ll>> ans(n, ve <ll> (m, 0));
        frn(i, b-1, 0)
        {
            ans[0][m-b+i]=1;
        }
        fr(i, 0, a-b-1) 
        {
            ans[0][i]=1;
        }
        fr(i, 1, n-1)
        {
            fr(j, 0, m-1)
            {
                ans[i][j]=ans[i-1][(j-1+m)%m];
            }
        }
        if(f)
        {
            fr(i, 0, m-1)
            {
                fr(j, 0, n-1)
                {
                    cout<<ans[j][i];
                }
                cout<<endl;
            }
        }
        else
        {
            fr(i, 0, n-1)
            {
                fr(j, 0, m-1)
                {
                    cout<<ans[i][j];
                }
                cout<<endl;
            }   
        }
    }
}