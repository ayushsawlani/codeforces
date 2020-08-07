#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    pair <char,ll> arr[n];
    ll arr_c=0;
    ll c=1;
    for(ll i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
        {
            c++;
        }
        else
        {
            arr[arr_c].first=s[i];
            arr[arr_c].second=c;
            c=1;
            arr_c++;
        }
        
    }
    arr[arr_c].first=s[n-1];
    arr[arr_c].second=c;
    arr_c++;
    ll i=0,j=0;
    ll b_count=0;
    ll total=0,ans=0;
    while((j<n)&&(i<n))
    {
        while((b_count<=k)&&(j<n))
        {
            if(s[j]=='b')
                b_count++;
            total++;
            j++;
        }
        if(b_count>k)
        {
            j--;
            b_count--;
            total--;
        }
        ans=max(total,ans);
        while((b_count>=k)&&(i<j))
        {
            if(s[i]=='b')
                b_count--;
            total--;
            i++;
        }
        if(i==j)
        {
            j++;
            i++;
        }
    }
    i=0,j=0;
    b_count=0;
    total=0;
    while((j<n)&&(i<n))
    {
        while((b_count<=k)&&(j<n))
        {
            if(s[j]=='a')
                b_count++;
            total++;
            j++;
        }
        if(b_count>k)
        {
            b_count--;
            total--;
            j--;
        }
        ans=max(total,ans);
        while((b_count>=k)&&(i<j))
        {
            if(s[i]=='a')
                b_count--;
            total--;
            i++;
        }
        if(j==i)
        {
            j++;
            i++;
        }
    }
    cout<<ans<<endl; 
}
