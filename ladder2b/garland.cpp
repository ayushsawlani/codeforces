#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    ll len_s1=s1.size();
    ll len_s2=s2.size();
    ll ans=0;
    ll arr1[26],arr2[26];
    for(ll i=0;i<26;i++)
    {
        arr1[i]=0;
        arr2[i]=0;
    }
    for(ll i=0;i<len_s1;i++)
    {
        arr1[(int)s1[i]-97]++;
    }
    for(ll i=0;i<len_s2;i++)
    {
        arr2[(int)s2[i]-97]++;
    }
    ll flag=0;
    for(ll i=0;i<26;i++)
    {
        if((arr2[i])&&(!arr1[i]))
        {
            flag=1;
            break;
        }
        else
        {
            if(arr2[i]<arr1[i])
                ans+=arr2[i];
            else
            {
                ans+=arr1[i];
            }
            
        }
        
    }
    if(flag)
        cout<<-1<<endl;
    else
    {
        cout<<ans<<endl;
    }
    
}