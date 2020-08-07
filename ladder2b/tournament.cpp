#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll x=((((n)*(n-1)))/2)-1;
    ll c_arr[n],win_arr[n];
    for(ll i=0;i<n;i++)
    {
        c_arr[i]=0;
        win_arr[i]=0;
    }
    for(ll i=0;i<x;i++)
    {
        ll temp1,temp2;
        cin>>temp1>>temp2;
        temp1--;
        temp2--;
        c_arr[temp1]++;
        c_arr[temp2]++;
        win_arr[temp1]++;
    }
    ll a1,a2;
    for(ll i=0;i<n;i++)
    {
        if(c_arr[i]==n-2)
        {
            a1=i;
        }
    }
    for(ll i=0;i<n;i++)
    {
        if(c_arr[i]==n-2)
        {
            a2=i;
            break;
        }
    }
    if(win_arr[a1]>win_arr[a2])
        cout<<a1+1<<" "<<a2+1<<endl;
    else
    {
        cout<<a2+1<<" "<<a1+1<<endl;
    }
    
}