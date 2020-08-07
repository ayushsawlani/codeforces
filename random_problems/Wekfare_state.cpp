#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    ll flag[n];
    memset(flag,0,n*sizeof(ll));
    ll q;
    cin>>q;
    vector <ll> query[q];
    for(ll i=0;i<q;i++)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll a1,a2;
            cin>>a1>>a2;
            a1--;
            query[i].push_back(a1);
            query[i].push_back(a2);
        }
        else
        {
            ll a1;
            cin>>a1;
            query[i].push_back(a1);
        }
    }
    ll max_array[q];
    memset(max_array,0,q*sizeof(ll));
    if(query[q-1].size()==1)
    {
        max_array[q-1]=query[q-1][0];
    }
    for(ll i=q-2;i>=0;i--)
    {
        if(query[i].size()==1)
        {
            max_array[i]=max(max_array[i+1],query[i][0]);
        }
        else
        {
            max_array[i]=max_array[i+1];   
        }
        
    }
    /*for(ll i=0;i<q;i++)
    {
        cout<<max_array[i]<<endl;
    }*/
    for(ll i=0;i<q;i++)
    {
        if(query[i].size()==2)
        {
            a[query[i][0]]=max(max_array[i],query[i][1]);
            flag[query[i][0]]=1;
        }
    }
    for(ll i=0;i<n;i++)
    {
        if(flag[i]==0)
        {
            a[i]=max(max_array[0],a[i]);
        }   
    }
    for(ll i=0;i<n;i++)
    {
        cout<<a[i]<<" ";

    }
    cout<<endl;
}