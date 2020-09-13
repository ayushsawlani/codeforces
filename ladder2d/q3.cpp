#include <bits/stdc++.h>
using namespace std;
#define M (1e9+7)
#define ll long long
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n,m;
    cin>>n>>m;
    ll a[2*(ll)pow(2,n)-1],level[2*(ll)pow(2,n)-1];
    memset(level,0,(2*(ll)pow(2,n)-1)*sizeof(ll));
    for(ll i=pow(2,n)-1;i<2*pow(2,n)-1;i++)
    {
        cin>>a[i];
    }
    ll i=pow(2,n)-1;
    while(i--)
    {
        level[i]=level[2*i+1]+1;
        if(level[i]%2==1)
            a[i]=a[2*i+1]|a[2*i+2];
        else
        {
            a[i]=a[2*i+1]^a[2*i+2];
        }
    }
    for(ll it=0;it<m;it++)
    {
        ll p,b;
        cin>>p;
        cin>>b;
        p--;
        a[(ll)pow(2,n)-1+p]=b;
        i=(ll)(pow(2,n))-1+p;
        while(i>0)
        {
            i=(i-1)/2;
            if(level[i]%2==1)
                a[i]=a[2*i+1]|a[2*i+2];
            else
                a[i]=a[2*i+1]^a[2*i+2];
        }
        cout<<a[0]<<endl;
    }
    return 0;
}