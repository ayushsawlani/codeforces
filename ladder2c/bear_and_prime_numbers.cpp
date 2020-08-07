#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 20000090
ll a[M];
int c_arr[M];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<M;i++)
    {
        c_arr[i]=0;
        a[i]=0;
    }
    int n;
    cin>>n;
    for(int j=0;j<n;j++)
    {
        int temp;
        cin>>temp;
        a[temp]++;
    }
    for(ll i=2;i<M;i++)
    {
        for(ll j=i*i;j<M;j=j+i)
            c_arr[j]=1;
    }
    for(long long  i=2;i<M;i++)
    {
        if(c_arr[i]==0)
        {
        for(long long j=2*i;j<M;j=j+i)
        {
            a[i]=a[i]+a[j];
        }
        }
    }
    for(int i=1;i<M;i++)
    {
        if(!(c_arr[i]))
        {
            a[i]+=a[i-1];
        }
        else
        {
            a[i]=a[i-1];
        }
        
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        ll l,r;
        cin>>l>>r;
        ll x=M;
        r=min(r,x-1);
        l=min(l,x-1);
        cout<<a[r]-a[l-1]<<endl;
    }
    
}