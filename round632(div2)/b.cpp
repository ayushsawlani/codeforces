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
        ll n;
        cin>>n;
        ve <ll> a(n);
        ve <ll> b(n);
        inarr(i,a,n);
        inarr(i,b,n);
        ll flag1=n+1;
        ll flag2=n+1;
        fr(i,0,n)
        {
            if((a[i]==1)&&(flag1==n+1))
                flag1=i;
            if((a[i]==-1)&&(flag2==n+1))
                flag2=i;
        }
        ll done=0;
        frn(i,n-1,-1)
        {
            if(a[i]<b[i])
            {
                if(flag1>=i)
                {
                    cout<<"NO"<<endl;
                    done=1;
                    break;
                }
            }
            if(a[i]>b[i])
            {
                if(flag2>=i)
                {
                    cout<<"NO"<<endl;
                    done=1;
                    break;
                }
            }
        }
        if(done==0)
            cout<<"YES"<<endl;
    }
}