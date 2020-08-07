#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    ll flag=0;
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]==0)
            flag=1;
        sum+=arr[i];
    }
    if((flag==0))
        cout<<-1<<endl;
    else 
    {
        ll valid[n];
        for(ll i=0;i<n;i++)
        {
            valid[i]=0;
        }
        sort(arr,arr+n);
        if(sum%3==1)
        {
            ll flag1=0;
            for(ll i=0;i<n;i++)
            {
                if(arr[i]%3==1)
                {
                    valid[i]=1;
                    flag1=1;
                    break;
                }
            }
            if(flag1==0)
            {
                ll c=0;
                for(ll i=0;i<n;i++)
                {
                    if(c==2)
                        break;
                    if(arr[i]%3==2)
                    {
                        c++;
                        valid[i]=1;
                    }
                }
            }
        }
        else if(sum%3==2)
        {
            ll flag1=0;
            for(ll i=0;i<n;i++)
            {
                if(arr[i]%3==2)
                {
                    valid[i]=1;
                    flag1=1;
                    break;
                }
            }
            if(flag1==0)
            {
                ll c=0;
                for(ll i=0;i<n;i++)
                {
                    if(c==2)
                        break;
                    if(arr[i]%3==1)
                    {
                        c++;
                        valid[i]=1;
                    }
                }
            }
        }
        ll flag2=0;
        for(ll i=0;i<n;i++)
            if(valid[i]==0)
            {
                if(arr[i]!=0)
                    flag2=1;
            }
        if(flag2)
        {
        for(ll i=n-1;i>=0;i--)
            if(valid[i]==0)
                cout<<arr[i];
        cout<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
        
    }
    
    
    
    
    
}