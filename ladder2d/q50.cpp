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
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
int main()
{
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    //fastio
    ll m, k;
    ve <ll> c1(103,0), c2(103,0);
    cin>>m>>k;
    set <ll> fav;
    fr(i, 0, k-1)
    {
        ll _t;
        cin>>_t;
        fav.insert(_t);
    }
    ll n;
    cin>>n;
    ve <ve <ll>> film(n, ve <ll> (2, 0));
    ll m1=-1;
    ll m2=-1;
    fr(i, 0, n-1)
    {
        string _t;
        cin>>_t;
        ll _n;
        cin>>_n;
        fr(_it, 0, _n-1)
        {
            ll temp;
            cin>>temp;
            if(temp==0)
                film[i][1]++;
            if(fav.find(temp)!=fav.end())
            {
                film[i][0]++;
            }
        }
        if(_n==m)
        {
            film[i][0]=k;
            film[i][1]=k;
        }
        else
        {
            film[i][1]+=film[i][0];
        }
        c1[film[i][0]]++;
        c2[film[i][1]]++;
        m1=max(m1, film[i][0]);
        m1=min(m1,k);
        m2=max(m2, film[i][1]);
        m2=min(m2,k);
    }
    ll f=0;
    fr(i, 0, n-1)
    {
        if((film[i][0]==m1)&&(film[i][1]>m1))
            f=1;
    }
    fr(i, 0, n-1)
    {
        if(film[i][1]<m1)
        {
            cout<<"1"<<endl;
        }
        else if((film[i][1]==m1)&&(f))
        {
                cout<<1<<endl;
            
        }
        else if((film[i][0]==m2)&&(c1[film[i][0]]==1))
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<"2"<<endl;
        }
        
        
    }
}