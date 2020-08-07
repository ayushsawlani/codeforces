#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll m,s;
    cin>>m>>s;
    ll s1=s;
    ll arr[m];
    ll i=m-1;
    ll j;
    

    if((s1==0)||(s>9*m))
    {
        if((m!=1)||(s>9*m))
            cout<<-1<<" "<<-1;  
        else
        {
            cout<<0<<" "<<0;
        }
        
    }
    else if(s1>1)
    {
        ll arr2[m];
            while(i>=0)
        {
            if(s>=9)
            {
                arr[i]=9;
                s=s-9;
            }
            else
            {
                arr[i]=s;
                s=s-s;
            }
            if(arr[i]>0)
                j=i;
            i--;
        }
        for(ll i=0;i<m;i++)
            arr2[i]=arr[i];
        if(arr[0]==0)
        {
            arr[0]=1;
            arr[j]--;
        }
        for(ll i=0;i<m;i++)
            cout<<arr[i];
        cout<<" ";
        for(ll i=0;i<m;i++)
            cout<<arr2[m-i-1];
    }
     else
    {
        cout<<1;
         for(ll i=1;i<m;i++)
            cout<<0;
        cout<<" ";
        cout<<1;
         for(ll i=1;i<m;i++)
            cout<<0;
    }
    
    cout<<endl;
}