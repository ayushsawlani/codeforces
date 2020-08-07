#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,m;
    cin>>n>>m;
    ll arr[n],arr_c=0;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        if(x<0)
            arr[arr_c++]=x;
    }
    sort(arr,arr+arr_c);
    int sum=0;
    for(int i=0;(i<arr_c)&&(i<m);i++)
    {
        sum+=arr[i];
    }
    cout<<(-1)*sum<<endl;
}