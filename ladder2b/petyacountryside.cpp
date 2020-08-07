#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    ll a[n+1];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    a[n]=-1;
    pair <ll,ll> b[n];
    ll i=0,c=1,b_c=0,max1=0,max2=0,max3=0;
    while(1)
    {
        if(i==n)
            break;
        if(a[i]==a[i+1])
            c++;
        else
        {
            b[b_c].first=a[i];
            b[b_c].second=c;
            b_c++;
            c=1;
        }
        i++;
    }
  /*  for(ll i=0;i<b_c;i++)
        cout<<b[i].first<<" "<<b[i].second<<endl;
    */    
    i=0;
    ll s=0,len=b[0].second;
    while(i<b_c-1)   
    {
        if(b[i].first<b[i+1].first)
        {
            s=1;
            len+=b[i+1].second;
        }
        else
        {
            s=0;
            max1=std::max(len,max1);
            len=b[i+1].second;
        }
        i++;
    }
    max1=std::max(max1,len);
    len=b[0].second;
    i=0;
    while(i<b_c-1)   
    {
        if(b[i].first>b[i+1].first)
        {
            len+=b[i+1].second;
        }
        else
        {
            max2=std::max(len,max2);
            len=b[i+1].second;
        }
        i++;
    }
    max2=std::max(max2,len);
    s=0;
    i=0;
    while(i<b_c-1)
    {
        if(b[i].first<b[i+1].first)
            break;
        i++;
    }
    len=b[i].second;
    while(i<b_c-1)
    {
        
        if(s==0)
        {
            if(b[i].first>b[i+1].first)
                s=1;
            len+=b[i+1].second;
        }
        else if(s==1)
        {
            if(b[i].first>b[i+1].first)
                len+=b[i+1].second;
            else
            {
                s=0;
                max3=max(max3,len);
                len=b[i].second+b[i+1].second;
            }
            
        }
        i++;
    }
    max3=max(max3,len);
    ll max=std::max(max3,max2);
    max=std::max(max,max1);
    cout<<max<<endl;
}